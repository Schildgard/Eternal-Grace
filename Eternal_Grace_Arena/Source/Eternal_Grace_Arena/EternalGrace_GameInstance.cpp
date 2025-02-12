// Fill out your copyright notice in the Description page of Project Settings.


#include "EternalGrace_GameInstance.h"
#include "CustomPlayerController.h"
#include "PlayerCharacter.h"
#include "EternalGrace_PlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "HealthComponent.h"
#include "BlendingWidget.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

UEternalGrace_GameInstance::UEternalGrace_GameInstance()
{
	//IT IS CRUCIAL THAT THE MAIN LEVEL IS NAMED EXACTLY THE SAME WAY AS THIS PROPERTY
	MainWorldName = FName("Level_Hub");
	WinCondition = false;
	LoadingScreen = nullptr;
}

void UEternalGrace_GameInstance::UploadHealthInfo(float HealthFromPlayer)
{
	CurrentHealth = HealthFromPlayer;
}

float UEternalGrace_GameInstance::GetHealthInfo()
{
	return CurrentHealth;
}

void UEternalGrace_GameInstance::ResetHealthInformation()
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (PlayerCharacter)
	{
		CurrentHealth = PlayerCharacter->HealthComponent->MaxHealth;
	}
	else
		UE_LOG(LogTemp, Error, TEXT("GameInstance: Failed to Cast Player On HealthInfoReset"))
}

void UEternalGrace_GameInstance::OnMapEnter(UWorld* LoadedWorld)
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//SAVE VALUES TO PLAYER STATE
	if (PlayerCharacter)
	{
		PlayerCharacter->HealthComponent->CurrentHealth = GetHealthInfo();
	}
	else
	{

		UE_LOG(LogTemp, Error, TEXT("GameInstance: Failed to Cast Player On Map Enter Function"))
	}
}

void UEternalGrace_GameInstance::OnMapLeave()
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//SAVE VALUES TO PLAYER STATE
	if (PlayerCharacter)
	{
		UploadHealthInfo(PlayerCharacter->HealthComponent->CurrentHealth);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("GameInstance: Failed to Cast Player On Map Leave Function"))
	}

	if (LoadingScreenClass)
	{
			LoadingScreen = CreateWidget<UBlendingWidget>(this, LoadingScreenClass);
		if (LoadingScreen)
		{
			//ACTIVATE LOADING SCREEN TO VIEWPORT
			LoadingScreen->AddToViewport();
			if (LoadingScreen->BlendingAnimation)
			{
				LoadingScreen->PlayAnimation(LoadingScreen->BlendingAnimation);
				FWidgetAnimationDynamicEvent load;
				load.BindDynamic(this, &UEternalGrace_GameInstance::LoadLevel);
				LoadingScreen->BindToAnimationFinished(LoadingScreen->BlendingAnimation, load);
			}
		}
	}
}

void UEternalGrace_GameInstance::SetObjectState(FName ObjectID, bool NewValue)
{
	//FIND RETURNS A POINTER TO THE VALUE OF THE KEY OR NULLPTR IF KEY NOT EXISTS
	bool* FoundValue = ObjectStates.Find(ObjectID);
	if (FoundValue)
	{
		*FoundValue = NewValue;
	}
	else
	{
		ObjectStates.Add(ObjectID, NewValue);
	}
	OnObjectStateChange.Broadcast();

	// ON EVERY STATE CHANGE, CHECK OF ALL STATES FOR WIN CONDITION ARE MET
	if (!WinCondition)
	{
		CheckWinConditionChange();
	}
}

void UEternalGrace_GameInstance::ReturnToMainLevel()
{
	if (!MainWorldName.IsNone())
	{
		UGameplayStatics::OpenLevel(GetWorld(), MainWorldName);
	}
	else UE_LOG(LogTemp, Error, TEXT("Mainworld Name in GameInstance seems to be None, which is invalid"))

}

FName UEternalGrace_GameInstance::GetMainWorldName()
{
	return MainWorldName;
}

void UEternalGrace_GameInstance::CheckWinConditionChange()
{
	UE_LOG(LogTemp, Error, TEXT("CHECK WIN CONDITION"))
		//ITERATE THROUGH EVERY WIN CONDITION
		for (const TPair<FName, bool>& Dependency : WinConditionDependencies)
		{
				//CHECK IF THIS CONDITION IS MET IN OBJECTSTATES
				if (bool* ConditionIsMet = ObjectStates.Find(Dependency.Key))
				{
					if (*ConditionIsMet != Dependency.Value)
					{
							return;
					}
				}
				else
				{
					return;
				}
			UE_LOG(LogTemp, Error, TEXT("win condition %s MET"), *Dependency.Key.ToString())
		}


	UE_LOG(LogTemp, Error, TEXT("ALL WIN CONDITION MET"))
		WinCondition = true;
	ObjectStates.Add("Exit", true);
}

void UEternalGrace_GameInstance::SetLevelToLoad(FName LevelName)
{
	LevelNameToLoad = LevelName;
}

void UEternalGrace_GameInstance::LoadLevel()
{
	// CREATE SOFT PATH TO LEVEL. THIS IS NECCESSARY DUE TO COMPLICATIONS ON LEVEL LOAD/UNLOAD WHILE USING REGULAR POINTERS
	FString LevelPath = FString::Printf(TEXT("/Game/Levels"), *LevelNameToLoad.ToString());
	FSoftObjectPath LevelSoftPath(LevelPath);
	if (LevelSoftPath.IsValid())
	{
		FStreamableManager& StreamManager = UAssetManager::GetStreamableManager();
		StreamManager.RequestAsyncLoad(LevelSoftPath, FStreamableDelegate::CreateUObject(this, &UEternalGrace_GameInstance::EnterLevel));
	}
	else UE_LOG(LogTemp, Warning, TEXT("%s Failed to create Softpath to Level"), *GetName())
}

void UEternalGrace_GameInstance::EnterLevel()
{
	if (!LevelNameToLoad.IsNone())
	{
		UGameplayStatics::OpenLevel(this, LevelNameToLoad);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("LoadLevel Function was called but LevelToLoad could not be getted."))
	}
}

bool UEternalGrace_GameInstance::GetWinCondition()
{
	return WinCondition;
}


