// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 *
 */
class UStaminaComponent;
UCLASS()
class ETERNAL_GRACE_ARENA_API APlayerCharacter : public AEternal_Grace_ArenaCharacter
{
	GENERATED_BODY()

	APlayerCharacter();
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Component, meta = (AllowPrivateAccess))
	UStaminaComponent* StaminaComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Values, meta = (AllowPrivateAccess))
	float RunningStaminaConsumption;

protected:
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds) override;

	virtual void Sprint()override;
	virtual void CancelSprint()override;

	virtual void LightAttack()override;
	virtual void ChargeHeavyAttack()override;
	virtual void HeavyAttack()override;

};
