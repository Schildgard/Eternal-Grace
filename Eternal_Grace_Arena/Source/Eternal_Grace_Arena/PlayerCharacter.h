// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 *
 */
class UStaminaComponent;
class UPostProcessComponent;
UCLASS()
class ETERNAL_GRACE_ARENA_API APlayerCharacter : public AEternal_Grace_ArenaCharacter
{
	GENERATED_BODY()

	APlayerCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* HeavyAttackAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* SprintAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* GuardCounterAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* InteractAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* DodgeAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PostProcessing, meta = (AllowPrivateAccess))
	UPostProcessComponent* DefaultPostProcess;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PostProcessing, meta = (AllowPrivateAccess))
	UPostProcessComponent* PoisonPostProcess;

public:
	//STAMINA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attribtues, meta = (AllowPrivateAccess))
	UStaminaComponent* StaminaComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attribtues, meta = (AllowPrivateAccess))
	float RunningStaminaConsumption;

	//GUARD COUNTER
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess))
	UAnimMontage* GuardCounter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	bool GuardCounterPossible;
	float const GuardCounterReactionTimer = 0.5f;
	UPROPERTY()
	float GuardCounterReactionCountdown;
	UFUNCTION()
	void GuardCounterAttack();

	UFUNCTION()
	UPostProcessComponent* GetPoisonPostProcessEffect();

	//INTERACT
	UFUNCTION()
	void Interact();


	//HEAVY ATTACK PROPERTIES
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes, meta = (AllowPrivateAccess))
	float currentChargePower;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes, meta = (AllowPrivateAccess))
	float maxChargePower = 2.5f;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* ChargeAttack;

	//SPRINT ATTACKS
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* RunningAttack;

	//INTERACT
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* InteractAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* DodgeMontage;


	UFUNCTION()
	void IncreaseChargePower();
	UFUNCTION()
	void SprintAttack();
	UFUNCTION()
	void Dodge();
	UFUNCTION()
	void Sprint();
	UFUNCTION()
	void CancelSprint();
	UFUNCTION()
	void ChargeHeavyAttack();
	UFUNCTION()
	void HeavyAttack();



	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void LightAttack()override;
	virtual void Guard()override;


};
