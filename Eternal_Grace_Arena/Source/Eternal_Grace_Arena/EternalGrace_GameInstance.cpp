// Fill out your copyright notice in the Description page of Project Settings.


#include "EternalGrace_GameInstance.h"
#include "CustomPlayerController.h"
#include "PlayerCharacter.h"
#include "EternalGrace_PlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "HealthComponent.h"

UEternalGrace_GameInstance::UEternalGrace_GameInstance()
{
	//IT IS CRUCIAL THAT THE MAIN LEVEL IS NAMED EXACTLY THE SAME WAY AS THIS PROPERTY
	MainWorldName = FName("Level_Main");
	WinCondition = false;
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
	else UE_LOG(LogTemp, Error, TEXT("GameInstance: Failed to Cast Player On Map Enter Function"))
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
		UE_LOG(LogTemp, Error, TEXT("GameInstance: Failed to Cast Player On Map Leave Function"))
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
		//		//ITERATE THROUGH DICTIONARY
		//		for (const TPair<FName, bool>& Depency : WinConditionDependencies)
		//		{
		//			//SET ACTIVE STATUS TO TRUE IF THE STATUS OF ALL RELATED OBJECTS MEETS EXPECTED CRITERIA
		//			if (Depency.Value != true)
		//			{
		//				return;
		//			}
		//		}
		//		WinCondition = true;
		//		ObjectStates.Add("Exit", true);
		//		UE_LOG(LogTemp, Error, TEXT("WIN CONDITION MET"))
		//			return;
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
	UE_LOG(LogTemp, Error, TEXT("PERFORM WIN CONDITION CHECK"))
		//ITERATE THROUGH EVERY WIN CONDITION
		for (const TPair<FName, bool>& Dependency : WinConditionDependencies)
		{
			UE_LOG(LogTemp, Error, TEXT("CHECK WINCONDITION: %s"), *Dependency.Key.ToString())
				//CHECK IF THIS CONDITION IS MET IN OBJECTSTATES
				if (bool* ConditionIsMet = ObjectStates.Find(Dependency.Key))
				{
					UE_LOG(LogTemp, Error, TEXT("WIN CONDITION IS IN ObJECT STATES "));
					if (*ConditionIsMet != Dependency.Value)
					{
						UE_LOG(LogTemp, Error, TEXT("Condition is not Met %s"), *Dependency.Key.ToString())
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


