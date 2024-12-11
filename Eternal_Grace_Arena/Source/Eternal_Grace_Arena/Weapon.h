// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API AWeapon : public AStaticMeshActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Property, meta = (AllowPrivateAccess))
	float DamageMultiplier;
};
