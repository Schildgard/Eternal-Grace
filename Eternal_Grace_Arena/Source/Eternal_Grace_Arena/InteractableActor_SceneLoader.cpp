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
	//LevelToLoad = nullptr;
}

void AInteractableActor_SceneLoader::Interact_Implementation()
{
	//CHECK IF LEVEL TO LOAD IS ASSIGNED AND VALID
	if (!LevelToLoad.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load Level. Its probably nullptr"))
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


	//GET PLAYER CONTROLLER AND SUSCRIBE ITS FUNCTION TO ON INTERACT
//	APlayerController* ActiveController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
//	ACustomPlayerController* CustomController = Cast<ACustomPlayerController>(ActiveController);
//	if (CustomController)
//	{
//		//
//		OnInteract.AddDynamic(CustomController, &ACustomPlayerController::OnMapLeave);
//		//FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(CustomController, &ACustomPlayerController::OnMapEnter);
//
//	}
//	else UE_LOG(LogTemp, Error, TEXT("No Controller for Interactable Actor"))






	UGameInstance* CurrentInstance = UGameplayStatics::GetGameInstance(GetWorld());
	UEternalGrace_GameInstance* CustomGameInstance = Cast<UEternalGrace_GameInstance>(CurrentInstance);
	if (CustomGameInstance)
	{
		UE_LOG(LogTemp, Error, TEXT("Cast to GameInstance Successfull"))

		OnInteract.AddDynamic(CustomGameInstance, &UEternalGrace_GameInstance::OnMapLeave);
		FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(CustomGameInstance, &UEternalGrace_GameInstance::OnMapEnter);
	}

}

void AInteractableActor_SceneLoader::OnLevelLoaded(UWorld* LoadedWorld)
{


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
		UE_LOG(LogTemp, Warning, TEXT("Failed to load Level"))
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
