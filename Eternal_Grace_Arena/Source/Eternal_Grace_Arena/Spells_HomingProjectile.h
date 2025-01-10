// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spells_Projectile.h"
#include "Spells_HomingProjectile.generated.h"

/**
 * 
 */
class AEternal_Grace_ArenaCharacter;
UCLASS()
class ETERNAL_GRACE_ARENA_API ASpells_HomingProjectile : public ASpells_Projectile
{
	GENERATED_BODY()
public:
	ASpells_HomingProjectile() : ASpells_Projectile() {};
	ASpells_HomingProjectile(AEternal_Grace_ArenaCharacter* LockedOnTarget);

protected:
	UPROPERTY()
	AEternal_Grace_ArenaCharacter* Target;

	virtual void BeginPlay()override;
	
};
