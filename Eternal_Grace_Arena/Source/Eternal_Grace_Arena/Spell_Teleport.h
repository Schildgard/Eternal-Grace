// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "Spell_Teleport.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API ASpell_Teleport : public ASpell
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void Teleport();


};
