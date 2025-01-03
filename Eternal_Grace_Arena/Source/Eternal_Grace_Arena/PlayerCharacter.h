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
	//STAMINA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Component, meta = (AllowPrivateAccess))
	UStaminaComponent* StaminaComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Values, meta = (AllowPrivateAccess))
	float RunningStaminaConsumption;

	//LOCKON PROPERTIES
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* ToggleLockOnAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* SwitchLockOnTargetAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LockOn, meta = (AllowPrivateAccess))
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LockOn, meta = (AllowPrivateAccess))
	AActor* LockedOnTarget;



	//LOCK ON FUNCTIONS
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void ToggleLockOn();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void SwitchLockOnTarget();
	UFUNCTION(CallInEditor, Category = Actions)
	AActor* FindNearestTarget();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual TArray<AActor*> ScanForTargets();
	UFUNCTION(CallInEditor, Category = Actions)
	void EngageLockOn(AActor* Target);
	UFUNCTION(CallInEditor, Category = Actions)
	void DisengageLockOn();


	//GUARD COUNTER
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* GuardCounterAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	bool GuardCounterPossible;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess))
	UAnimMontage* GuardCounter;
	float const GuardCounterReactionTimer = 0.5f;
	UPROPERTY()
	float GuardCounterReactionCountdown;
	UFUNCTION()
	void GuardCounterAttack();

	//INTERACT
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* InteractAction;
	UFUNCTION()
	void Interact();


protected:
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Sprint()override;
	virtual void CancelSprint()override;


	virtual void LightAttack()override;
	virtual void ChargeHeavyAttack()override;
	virtual void HeavyAttack()override;

	virtual void Guard()override;

};
