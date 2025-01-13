// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Damage_Spells.h"
#include "Spells_Projectile.generated.h"

/**
 * 
 */
class UProjectileMovementComponent;
UCLASS()
class ETERNAL_GRACE_ARENA_API ASpells_Projectile : public ADamage_Spells
{
	GENERATED_BODY()
public:
	ASpells_Projectile();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	UProjectileMovementComponent* Movement;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	FVector Direction;

	virtual void Tick(float DeltaSeconds)override;
	virtual void DealDamage(AEternal_Grace_ArenaCharacter* Target)override;
};
