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
class UCharacterWeapon;
class UCharacterShield;
class UHealthComponent;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config = Game)
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

	//CUSTOM ACTION STATES
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
	TArray<UAnimMontage*> LightAttacks;
	//HEAVY ATTACKS
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	TArray<UAnimMontage*> HeavyAttacks;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* ChargeAttack;
	//SPRINT ATTACKS
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* RunningAttack;
	//GUARD COUNTER ATTACK
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* GuardCounterAttack;
	//GUARD
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* GuardBreakEvent;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* Block;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* BlockHeavyAttack;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitEffect, meta = (AllowPrivateAccess))
	UPhysicalMaterial* PhysicalMaterial;
	//STAGGER
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	TArray<UAnimMontage*> StaggerAnims;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	TArray<UAnimMontage*> StaggerAnimsBack;

	//DODGE
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* DodgeAction;

	//INTERACT
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* Interact;

	//Death
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* DeathAnimation;

	//CUSTOM VALUE PROPERTIES
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	float currentChargePower;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess))
	float maxChargePower = 2.5f;

	//GENERAL
	UPROPERTY()
	UWorld* world;
public:
	//WEAPON
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	UCharacterWeapon* Weapon;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	FName WeaponSocket;
	//SHIELD
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	UCharacterShield* Shield;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	FName ShieldSocket;
	//LOCK ON SYSTEM
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LockOn, meta = (AllowPrivateAccess))
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LockOn, meta = (AllowPrivateAccess))
	AActor* LockedOnTarget;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LockOn, meta = (AllowPrivateAccess))
	UHealthComponent* HealthComponent;


	UPROPERTY()
	class UCharacterAnimInstance* CharacterAnimationInstance;

public:
	AEternal_Grace_ArenaCharacter();


protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	//MOVEMENT FUNCTIONS
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void Sprint();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void CancelSprint();

	//ATTACK FUNCTIONS
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void LightAttack();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void HeavyAttack();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void ChargeHeavyAttack();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void IncreaseChargePower();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void SprintAttack();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void GuardCounter();

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
	public:
	UFUNCTION(CallInEditor, Category = Actions)
	void RotateTowardsTarget(AActor* Target);
	protected:
	//GUARD
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void Guard();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void CancelGuard();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void BlockAttack();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void BlockHeavy();
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void GuardBreak();

	//DODGE
	UFUNCTION(CallInEditor, Category = Actions)
	virtual void Dodge();

protected:

	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay()override;


	virtual void Tick(float DeltaSeconds) override;

	void InitializeAnimationInstance();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

