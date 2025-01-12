// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaBoss.h"
#include "Enemy_WeaponMaster.generated.h"

/**
 * 
 */
class UStaggerComponent;
UCLASS()
class ETERNAL_GRACE_ARENA_API AEnemy_WeaponMaster : public AEternal_Grace_ArenaBoss
{
	GENERATED_BODY()




protected:
	AEnemy_WeaponMaster();
	virtual void LightAttack()override;
	//virtual void GetDamage_Implementation(float Damage, float PoiseDamage, float DamageDirection, EStaggeringType StaggerType, AEternal_Grace_ArenaCharacter* DamageSource)override;

	//STAGGERCOMPONENT
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attribtues, meta = (AllowPrivateAccess))
	UStaggerComponent* StaggerComponent;

	UFUNCTION()
	void GetOffMeMove();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations, meta = (AllowPrivateAccess))
	UAnimMontage* GetOffMeAttack;
};
