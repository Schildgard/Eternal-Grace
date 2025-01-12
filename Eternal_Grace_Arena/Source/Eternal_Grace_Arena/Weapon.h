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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float BaseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float StaminaCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	float PoiseDamage;
};


UCLASS()
class ETERNAL_GRACE_ARENA_API AWeapon : public AEquipment
{
	GENERATED_BODY()
	AWeapon();

protected:
	virtual void BeginPlay()override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float BaseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float StaminaCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float PoiseDamage;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	FWeaponStats Stats;

public:
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Collision)
//	TArray<AEternal_Grace_ArenaCharacter*> HittedActors;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Multipliers, meta = (AllowPrivateAccess))
	float DamageMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Multipliers, meta = (AllowPrivateAccess))
	EStaggeringType StaggerType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = HitEffect, meta = (AllowPrivateAccess))
	UDataTable* HitEffectDataTable;


	UFUNCTION()
	FWeaponStats GetWeaponStats();
	
};
