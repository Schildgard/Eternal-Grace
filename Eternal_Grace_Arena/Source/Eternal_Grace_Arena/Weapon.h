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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	FWeaponStats Stats;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Multipliers, meta = (AllowPrivateAccess))
	float DamageMultiplier;



	UFUNCTION()
	FWeaponStats GetWeaponStats();
	
};
