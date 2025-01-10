// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaEnemy.h"
#include "Eternal_Grace_ArenaEnemy_Caster.generated.h"

/**
 * 
 */
class USpellComponent;
class ASpell;
UCLASS()
class ETERNAL_GRACE_ARENA_API AEternal_Grace_ArenaEnemy_Caster : public AEternal_Grace_ArenaEnemy
{
	GENERATED_BODY()
	
protected:
	AEternal_Grace_ArenaEnemy_Caster();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	USpellComponent* SpellComponent;

	UPROPERTY()
	float TestTimer;
	UPROPERTY()
	float TestCountdown;


	UFUNCTION()
	void CastSpell();

	virtual void Tick(float DeltaSeconds)override;
};
