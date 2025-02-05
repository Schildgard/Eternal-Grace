// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaBoss.h"
#include "Enemy_MushroomKing.generated.h"

/**
 *
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API AEnemy_MushroomKing : public AEternal_Grace_ArenaBoss
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
TArray<UAnimMontage*> LightAttacks;
	virtual void GetOffMeMove()override;

	virtual void Tick(float DeltaSeconds)override;

	virtual void LightAttack()override;
	UFUNCTION()
	void Attack();
};
