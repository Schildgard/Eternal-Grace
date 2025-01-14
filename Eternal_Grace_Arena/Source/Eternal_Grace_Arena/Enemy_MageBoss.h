// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaBoss.h"
#include "Enemy_MageBoss.generated.h"

/**
 * 
 */
class ASpawnPoint;
class USpellComponent;
UCLASS()
class ETERNAL_GRACE_ARENA_API AEnemy_MageBoss : public AEternal_Grace_ArenaBoss
{
	GENERATED_BODY()

protected:
	AEnemy_MageBoss();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	USpellComponent* SpellComponent;
	UPROPERTY()
	TArray<ASpawnPoint*> SpawnPositions;
	//THIS ARRAY IS USED TO CONTROL IF THE CASTER CAN TELEPORT TO THE SAME POSITION MULTIPLE TIMES
	UPROPERTY()
	TArray<ASpawnPoint*> BlockedSpawnPositions;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	UAnimMontage* TeleportAnim;

	virtual void LightAttack()override;
	virtual void BeginPlay()override;

	UFUNCTION()
	void SetTeleportPosition();

public:
	UFUNCTION()
	USpellComponent* GetSpellComponent();
	
};
