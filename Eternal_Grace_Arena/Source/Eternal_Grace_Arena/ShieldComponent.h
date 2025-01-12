// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "StaggeringType.h"
#include "ShieldComponent.generated.h"

class AShield;
class AEternal_Grace_ArenaCharacter;
class APlayerCharacter;
class UCharacterAnimInstance;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ETERNAL_GRACE_ARENA_API UShieldComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UShieldComponent();

protected:
	virtual void BeginPlay() override;


	UPROPERTY()
	AEternal_Grace_ArenaCharacter* OwningCharacter;
	UPROPERTY()
	APlayerCharacter* OwningPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TSubclassOf<AShield> EquippedWeaponClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	AShield* EquippedShield;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TMap<EStaggeringType, UAnimMontage*> BlockAnimationMap;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	UAnimMontage* GuardBreakAnimation;


	UPROPERTY()
	UCharacterAnimInstance* OwnersAnimationInstance;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void BlockDamage(float Damage, float PoiseDamage, float DamageDirection, EStaggeringType StaggerType, AEternal_Grace_ArenaCharacter* DamageSource);

	UFUNCTION()
	void Guard();

	UFUNCTION()
	void CancelGuard();

	UFUNCTION()
	AShield* GetCurrentShield();

	UFUNCTION()
	void SetAnimationInstanceReference();

	UFUNCTION()
	bool CheckEquippedShieldClass();


};
