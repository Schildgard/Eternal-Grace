// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnManager.generated.h"

UCLASS()
class ETERNAL_GRACE_ARENA_API ASpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnManager();

protected:
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform)override;

	UPROPERTY()
	USceneComponent* Root;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Spawn Positions", meta = (AllowPrivateAccess))
	TArray<USceneComponent*> SpawnPositions;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn Positions", meta = (AllowPrivateAccess))
	TArray<AActor*> SpawnPositionActors;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	FVector GetPositionRandom();

	UFUNCTION()
	FVector GetPosition(int SpawnPositionIndex);

	UFUNCTION()
	void AddSpawnPosition();

};
