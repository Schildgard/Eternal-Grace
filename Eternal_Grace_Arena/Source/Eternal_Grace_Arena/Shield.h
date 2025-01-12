// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Equipment.h"
#include "Shield.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FShieldStats
{
	GENERATED_BODY()
	// PERCENTAGE VALUE
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	float PhysicalDamageReduction;
	//STABILITY REDUCES THE STAMINA CONSUMPTION PER SUCESSFULL BLOCK
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	float Stability;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Physics, meta = (AllowPrivateAccess))
	UPhysicalMaterial* PhysicalMaterial;

};


UCLASS()
class ETERNAL_GRACE_ARENA_API AShield : public AEquipment
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes, meta = (AllowPrivateAccess))
	FShieldStats Stats;
public:
	UFUNCTION()
	FShieldStats GetShieldStats();
	
};
