// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor_SceneLoader.h"
#include "Kismet/GameplayStatics.h"

AInteractableActor_SceneLoader::AInteractableActor_SceneLoader()
{
	LevelToLoad = nullptr;
}

void AInteractableActor_SceneLoader::Interact_Implementation()
{
	if(LevelToLoad)
	{
	UGameplayStatics::OpenLevel(this, LevelToLoad->GetFName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load Level. Its probably nullptr"))
	}
}
