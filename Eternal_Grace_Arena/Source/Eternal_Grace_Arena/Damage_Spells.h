// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spell.h"
#include "StaggeringType.h"
#include "Damage_Spells.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API ADamage_Spells : public ASpell
{
	GENERATED_BODY()


protected:
	ADamage_Spells();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	float DamageValue; //APPLY NEGATIVE VALUE FOR HEALING EFFECTS

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta =(AllowPrivateAccess))
	float PoiseDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	EStaggeringType StaggerType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	bool isBlockable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta =(AllowPrivateAccess))
	USoundBase* HitSFX;



	virtual void SpellEffect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)override;

	UFUNCTION()
	virtual void DealDamage(AEternal_Grace_ArenaCharacter* Target);
	
	UFUNCTION()
	float CalculateAttackAngle(AEternal_Grace_ArenaCharacter* Target);
};
