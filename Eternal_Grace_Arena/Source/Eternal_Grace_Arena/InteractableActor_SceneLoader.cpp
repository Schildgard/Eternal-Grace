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
	LevelToLoad = nullptr;
}

void AInteractableActor_SceneLoader::Interact_Implementation()
{
	//CHECK IF LEVEL TO LOAD IS ASSIGNED AND VALID
	if (!LevelToLoad.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("%s tried to load into Level to Load but failed miserably. Its probably nullptr"), *GetName())
			return;
	}
	else
	{
		//LOAD LEVEL ASYNC AND CALL FUNCTION WHEN FINISHED
		FStreamableManager& StreamManager = UAssetManager::GetStreamableManager();
		StreamManager.RequestAsyncLoad(LevelToLoad.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &AInteractableActor_SceneLoader::LoadLevel));
		// BROADCAST THAT A MAPCHANGE IS HAPPENING. LISTENERS ARE FOR EXAMPLE THE GAMEINSTANCE WHICH SAVES PLAYER VALUES AND RETURNS THEM TO NEW PLAYER INSTANCE ON LEVEL LOAD
		OnInteract.Broadcast();
	}
}

void AInteractableActor_SceneLoader::BeginPlay()
{
	Super::BeginPlay();
	if (!LevelToLoad.IsValid())
	{
		LevelToLoad.LoadSynchronous();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s has a LeevlPointer which is not Valid. Interactions with it wont work"), *GetName())
	}

	UGameInstance* CurrentInstance = UGameplayStatics::GetGameInstance(GetWorld());
	UEternalGrace_GameInstance* CustomGameInstance = Cast<UEternalGrace_GameInstance>(CurrentInstance);
	if (CustomGameInstance)
	{
			OnInteract.AddDynamic(CustomGameInstance, &UEternalGrace_GameInstance::OnMapLeave);
		FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(CustomGameInstance, &UEternalGrace_GameInstance::OnMapEnter);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s failed to Cast to Custom GameInstance. Thus GameInstance could not Subscribe to its Interact Event"), *GetName())
	}
}

void AInteractableActor_SceneLoader::LoadLevel()
{
	UWorld* LoadedLevel = LevelToLoad.Get();
	if (LoadedLevel)
	{
		UGameplayStatics::OpenLevel(this, LoadedLevel->GetFName());
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
	//MAYBE LOADING THE LEVEL WHILE IN OVERLAP IS A GOOD IDEA
}

void AInteractableActor_SceneLoader::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	if (InteractInfoWidget && InteractInfoWidget->IsInViewport())
	{
		InteractInfoWidget->RemoveFromViewport();
	}
}
