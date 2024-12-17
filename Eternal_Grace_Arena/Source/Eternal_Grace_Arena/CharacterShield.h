// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "CharacterShield.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UCharacterShield : public UStaticMeshComponent
{
	GENERATED_BODY()
	UCharacterShield();
public:
	// PERCENTAGE VALUE
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	float PhysicalDamageReduction;
	//STABILITY REDUCES THE STAMINA CONSUMPTION PER SUCESSFULL BLOCK
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	float Stability;
	
};
