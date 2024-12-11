// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API AWeapon : public AActor
{
	AWeapon();
	GENERATED_BODY()
	public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Property, meta = (AllowPrivateAccess))
	UStaticMeshComponent* DamageMultiplier;
};
