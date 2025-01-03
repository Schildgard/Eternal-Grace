// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor_SceneLoader.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Blueprint/UserWidget.h"

AInteractableActor_SceneLoader::AInteractableActor_SceneLoader()
{
	//LevelToLoad = nullptr;
}

void AInteractableActor_SceneLoader::Interact_Implementation()
{
	if (!LevelToLoad.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load Level. Its probably nullptr"))
			return;
	}
	else
	{
		FStreamableManager& StreamManager = UAssetManager::GetStreamableManager();
		StreamManager.RequestAsyncLoad(LevelToLoad.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &AInteractableActor_SceneLoader::OnLevelLoaded));
	}
	InteractInfoWidget->AddToViewport();
}

void AInteractableActor_SceneLoader::BeginPlay()
{
	Super::BeginPlay();
	if (!LevelToLoad.IsValid())
	{
		LevelToLoad.LoadSynchronous();
	}
}

void AInteractableActor_SceneLoader::OnLevelLoaded()
{
	UWorld* LoadedLevel = LevelToLoad.Get();
	if(LoadedLevel)
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
}

void AInteractableActor_SceneLoader::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	if (InteractInfoWidget&& InteractInfoWidget->IsInViewport())
	{

		InteractInfoWidget->RemoveFromViewport();
	}
}
