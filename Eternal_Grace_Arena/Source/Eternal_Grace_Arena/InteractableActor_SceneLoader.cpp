// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor_SceneLoader.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Blueprint/UserWidget.h"
#include "EternalGrace_GameState.h"
#include "EternalGrace_GameInstance.h"

AInteractableActor_SceneLoader::AInteractableActor_SceneLoader()
{
	ActiveGameInstance = nullptr;
	isActive = true;
}

void AInteractableActor_SceneLoader::Interact_Implementation()
{
	if (isActive)
	{
		//CHECK IF LEVEL TO LOAD IS ASSIGNED AND VALID
		if (LevelNameToLoad.IsNone())
		{
			UE_LOG(LogTemp, Warning, TEXT("%s tried to load into Level to Load but failed miserably. Its probably nullptr"), *GetName())
				return;
		}
		else
		{
			// CREATE SOFT PATH TO LEVEL. THIS IS NECCESSARY DUE TO COMPLICATIONS ON LEVEL LOAD/UNLOAD WHILE USING REGULAR POINTERS
			FString LevelPath = FString::Printf(TEXT("/Game/Levels"), *LevelNameToLoad.ToString());
			FSoftObjectPath LevelSoftPath(LevelPath);
			if (LevelSoftPath.IsValid())
			{
				FStreamableManager& StreamManager = UAssetManager::GetStreamableManager();
				StreamManager.RequestAsyncLoad(LevelSoftPath, FStreamableDelegate::CreateUObject(this, &AInteractableActor_SceneLoader::LoadLevel));
				// BROADCAST THAT A MAPCHANGE IS HAPPENING. LISTENERS ARE FOR EXAMPLE THE GAMEINSTANCE WHICH SAVES PLAYER VALUES AND RETURNS THEM TO NEW PLAYER INSTANCE ON LEVEL LOAD
				OnInteract.Broadcast();
			} else UE_LOG(LogTemp, Warning, TEXT("%s Failed to create Softpath to Level"), *GetName())
		}
	}
	else
	{
		//INSERT NOTIFICATION THAT THE SCENE LOADING OBJECT IS UNACTIVE BECAUSE OF CONDITIONS IN GAMESTATE
		UE_LOG(LogTemp, Warning, TEXT("%s is not Active "), *GetName())
	}
}

void AInteractableActor_SceneLoader::BeginPlay()
{
	Super::BeginPlay();

//	UGameInstance* CurrentInstance = UGameplayStatics::GetGameInstance(GetWorld());
//	ActiveGameInstance = Cast<UEternalGrace_GameInstance>(CurrentInstance);
	if (ActiveGameInstance)
	{
		//ActiveGameInstance = ActiveGameInstance;
		OnInteract.AddDynamic(ActiveGameInstance, &UEternalGrace_GameInstance::OnMapLeave);
	//	ActiveGameInstance->OnObjectStateChange.AddDynamic(this, &AInteractableActor_SceneLoader::UpdateStatus);
		FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(ActiveGameInstance, &UEternalGrace_GameInstance::OnMapEnter);
		//SET IS ACTIVE DEPENDING ON DICTIONARY OF GAME INSTANCE
	//	if (ActiveGameInstance->ObjectStates.Contains(UniqueID))
	//	{
	//		isActive = ActiveGameInstance->ObjectStates[UniqueID];
	//		UE_LOG(LogTemp, Warning, TEXT("%s Got its Value from GameInstance"), *GetName())
	//	}
	//	else
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("GameInstance had the Key of %s yet, so its default active status is true"), *GetName())
	//	}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s failed to Cast to Custom GameInstance. Thus GameInstance could not Subscribe to its Interact Event"), *GetName())
	}
}

void AInteractableActor_SceneLoader::LoadLevel()
{
	//UWorld* LoadedLevel = LevelToLoad.Get();
	if (!LevelNameToLoad.IsNone())
	{
		UGameplayStatics::OpenLevel(this, LevelNameToLoad);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s LoadLevel Function was called but LevelToLoad could not be getted."), *GetName())
	}
}

void AInteractableActor_SceneLoader::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (InteractInfoWidget && !InteractInfoWidget->IsInViewport())
	{
		InteractInfoWidget->AddToViewport();
	}
}

void AInteractableActor_SceneLoader::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	if (InteractInfoWidget && InteractInfoWidget->IsInViewport())
	{
		InteractInfoWidget->RemoveFromViewport();
	}
}

//void AInteractableActor_SceneLoader::UpdateStatus()
//{
//
//	if (ActiveGameInstance && ActiveGameInstance->ObjectStates.Contains(UniqueID))
//	{
//		isActive = ActiveGameInstance->ObjectStates[UniqueID];
//	}
//	else
//	{
//		UE_LOG(LogTemp, Warning, TEXT("%s Could not Access GameInstance or GameInstance Dictionary did not Contained its key"), *GetName())
//	}
//}
