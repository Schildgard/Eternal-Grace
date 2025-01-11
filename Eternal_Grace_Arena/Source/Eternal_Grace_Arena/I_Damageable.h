// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "I_Damageable.generated.h"

class AEternal_Grace_ArenaCharacter;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UI_Damageable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ETERNAL_GRACE_ARENA_API II_Damageable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent)
	void GetDamage(float Damage, float PoiseDamage, float DamageDirection, EStaggeringType StaggerType, AEternal_Grace_ArenaCharacter* DamageSource);

	UFUNCTION(BlueprintNativeEvent)
	void Die();
};
