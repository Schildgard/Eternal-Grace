// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipment.h"
#include "Weapon.generated.h"

/**
 * 
 */
class AEternal_Grace_ArenaCharacter;
class UCapsuleComponent;
USTRUCT(BlueprintType)
struct FWeaponStats
{
	GENERATED_BODY()

	FWeaponStats(): BaseDamage(50.0f), StaminaCost(15.0f), PoiseDamage(20.0f){}
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float BaseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float StaminaCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float PoiseDamage;
};


UCLASS()
class ETERNAL_GRACE_ARENA_API AWeapon : public AEquipment
{
	GENERATED_BODY()
	AWeapon();

protected:
	virtual void BeginPlay()override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes, meta = (AllowPrivateAccess))
	FWeaponStats Stats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes, meta = (AllowPrivateAccess))
	UCapsuleComponent* ColliderComponent;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	TArray<UAnimMontage*> LightAttackMontages;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations, meta = (AllowPrivateAccess))
	TArray<UAnimMontage*> HeavyAttackMontages;

	

public:
	UFUNCTION()
	FWeaponStats GetWeaponStats();

	UFUNCTION()
	FTransform GetSocket(FName SocketName);

	UFUNCTION()
	UCapsuleComponent* GetColliderShape();

	UFUNCTION()
	TArray<UAnimMontage*> GetLightAttackMontages();

	UFUNCTION()
	TArray<UAnimMontage*> GetHeavyAttackMontages();
	
};
