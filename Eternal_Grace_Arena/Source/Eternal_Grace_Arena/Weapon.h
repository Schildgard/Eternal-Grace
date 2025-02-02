// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipment.h"
#include "StaggeringType.h"
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
	

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Attributes, meta = (AllowPrivateAccess))
	float DamageMultiplier;


	UFUNCTION()
	FWeaponStats GetWeaponStats();

	UFUNCTION()
	FTransform GetSocket(FName SocketName);

	UFUNCTION()
	UCapsuleComponent* GetColliderShape();
	
};
