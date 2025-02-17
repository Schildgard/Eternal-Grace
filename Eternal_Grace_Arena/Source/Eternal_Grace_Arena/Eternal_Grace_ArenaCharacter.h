// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "I_Damageable.h"
#include "StaggeringType.h"
#include "Eternal_Grace_ArenaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UHealthComponent;
class UStaggerComponent;
class UWeaponComponent;
class UShieldComponent;
class UStatusEffectComponent;
struct FInputActionValue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCharacterDeath);
DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config = Game)
class AEternal_Grace_ArenaCharacter : public ACharacter, public II_Damageable
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
	UInputAction* LightAttackAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess))
	UInputAction* GuardAction;


protected:
	AEternal_Grace_ArenaCharacter();

	
public:

	UPROPERTY()
	bool canAttack;
	UFUNCTION()
	void SetAttackStatus(UAnimMontage* AttackAnimation);

	//DEATH ANIMATIONS
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* DeathAnimation;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* DeathAnimationWithKnockBack;

	//GENERAL PROPERTIES
	UPROPERTY()
	UWorld* world;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitEffect, meta = (AllowPrivateAccess))
	UPhysicalMaterial* PhysicalMaterial;
	UPROPERTY()
	class UCharacterAnimInstance* CharacterAnimationInstance;

	//WEAPON
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Equipment, meta = (AllowPrivateAccess))
	FName WeaponSocket;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Equipment, meta = (AllowPrivateAccess))
	UWeaponComponent* WeaponComponent;



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Equipment, meta = (AllowPrivateAccess))
	FName ShieldSocket;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Equipment, meta = (AllowPrivateAccess))
	UShieldComponent* ShieldComponent;


	//HEALTH
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes, meta = (AllowPrivateAccess))
	UHealthComponent* HealthComponent;

	//STAGGERCOMPONENT
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attribtues, meta = (AllowPrivateAccess))
	UStaggerComponent* StaggerComponent;

	//STATUSEFFECTS
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes, meta = (AllowPrivateAccess))
	UStatusEffectComponent* StatusEffectComponent;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnCharacterDeath OnCharacterDeath;

	virtual void GetDamage_Implementation(float Damage, float PoiseDamage, float DamageDirection, EStaggeringType StaggerType, AEternal_Grace_ArenaCharacter* DamageSource, bool Blocked)override;
	virtual void Die_Implementation()override;
	virtual void FellOutOfWorld(const class UDamageType& dmgType);



protected:

	//COMBAT ACTION FUNCTIONS
	UFUNCTION(BlueprintCallable)
	virtual void LightAttack();
	UFUNCTION()
	virtual void Guard();
public:
	UFUNCTION()
	virtual void CancelGuard();
	UFUNCTION()
	UStatusEffectComponent* GetStatusEffectComponent();

public:
	UFUNCTION()
	void RotateTowardsTarget(AActor* Target);

	UFUNCTION()
	void QuitAttack();



protected:
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	virtual void NotifyControllerChanged() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay()override;
	virtual void Tick(float DeltaSeconds) override;
	void InitializeAnimationInstance();


public:
	virtual FVector GetTargetLocation(AActor* Requestor = nullptr) const override;
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

