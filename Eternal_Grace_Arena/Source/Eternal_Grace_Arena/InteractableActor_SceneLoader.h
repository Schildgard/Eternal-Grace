// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "InteractableActor_SceneLoader.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API AInteractableActor_SceneLoader : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	AInteractableActor_SceneLoader();
	virtual void Interact_Implementation()override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Scene Loading", meta = (AllowPrivateAccess))
	TSoftObjectPtr<UWorld> LevelToLoad;
};
