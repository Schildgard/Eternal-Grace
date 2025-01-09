// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = States, meta = (AllowPrivateAccess))
	bool isRunning;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = States, meta = (AllowPrivateAccess))
	bool isGuarding;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = States, meta = (AllowPrivateAccess))
	bool isWeaponSeathed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = States, meta = (AllowPrivateAccess))
	bool isLockedOn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = States, meta = (AllowPrivateAccess))
	bool isAttacking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = States, meta = (AllowPrivateAccess))
	bool isInHeavyAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State, meta = (AllowPrivateAccess))
	bool isCharging;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State, meta = (AllowPrivateAccess))
	bool isStaggered;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation, meta = (AllowPrivateAccess))
	int attackCount;
	//VALUE BETWEEN -180 AND 180 DEGREES, THAT INTERPOLATES BETWEEN STRAFE ANIMATIONS 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation, meta = (AllowPrivateAccess))
	float facingDirection;

	

	UFUNCTION()
	void InterruptAttack(UAnimMontage* AttackAnimation, bool Interrupted);
	void OnAttackEnd(UAnimMontage* AttackAnimation, bool Interrupted);

	
};
