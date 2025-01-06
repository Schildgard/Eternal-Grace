// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "CustomPlayerController.h"
#include "EternalGrace_GameInstance.h"
#include "InteractableActor_SceneLoader.generated.h"

/**
 *
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteraction);
class UEternalGrace_GameInstance;

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
	void LoadLevel();
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)override;
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)override;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scene Loading", meta = (AllowPrivateAccess))
	FName LevelNameToLoad;


	//COMMUNICATION WITH GAME INSTANCE
	UPROPERTY()
	UEternalGrace_GameInstance* ActiveGameInstance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Scene Loading", meta = (AllowPrivateAccess))
	bool isActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	FName UniqueID;

	UFUNCTION()
	void UpdateStatus();
};
