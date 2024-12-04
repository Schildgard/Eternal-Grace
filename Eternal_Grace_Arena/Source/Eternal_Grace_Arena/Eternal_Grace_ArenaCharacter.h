// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "Eternal_Grace_ArenaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AEternal_Grace_ArenaCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	//CUSTOM ACTIONS
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* SprintAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* LightAttackAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* HeavyAttackAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* GuardAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* ToggleLockOnAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* SwitchLockOnTargetAction;

	//LIGHT ATTACKS
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* LightAttack01;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* LightAttack02;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* LightAttack03;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* LightAttack04;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* LightAttack05;
	//HEAVY ATTACKS
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* HeavyAttack01;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* HeavyAttack02;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* ChargeAttack;

	//CUSTOM VALUE PROPERTIES
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	float currentChargePower;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess))
	float maxChargePower = 2.5f;

	//GENERAL
	UPROPERTY()
	UWorld* world;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LockOn, meta = (AllowPrivateAccess))
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LockOn, meta = (AllowPrivateAccess))
	TArray<AActor*> ActorsToIgnore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LockOn, meta = (AllowPrivateAccess))
	TArray<FHitResult> ViableTargets;


	UPROPERTY()
	class UCharacterAnimInstance* CharacterAnimationInstance;

public:
	AEternal_Grace_ArenaCharacter();
	

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	UFUNCTION(CallInEditor, Category = Actions)
	virtual void Sprint();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void CancelSprint();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void LightAttack();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void HeavyAttack();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void ChargeHeavyAttack();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void IncreaseChargePower();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void Guard();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void CancelGuard();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void ToggleLockOn();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void SwitchLockOnTarget();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void FindNearestTarget();



//private:
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation, meta = (AllowPrivateAccess))
//	int attackCount;
			

protected:

	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay()override;

	void InitializeAnimationInstance();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

