// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "CustomPlayerController.h"
#include "InteractableActor_SceneLoader.generated.h"

/**
 *
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteraction);

UCLASS()
class ETERNAL_GRACE_ARENA_API AInteractableActor_SceneLoader : public AInteractableActor
{
	GENERATED_BODY()

public:
	FOnInteraction OnInteract;
	AInteractableActor_SceneLoader();
	virtual void Interact_Implementation()override;
	virtual void BeginPlay()override;
	UFUNCTION()
	void OnLevelLoaded(UWorld* LoadedWorld);
	UFUNCTION()
	void LoadLevel();
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)override;
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scene Loading", meta = (AllowPrivateAccess))
	TSoftObjectPtr<UWorld> LevelToLoad;
};
