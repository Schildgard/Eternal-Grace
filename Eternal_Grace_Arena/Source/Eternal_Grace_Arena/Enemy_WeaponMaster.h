// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaBoss.h"
#include "Enemy_WeaponMaster.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API AEnemy_WeaponMaster : public AEternal_Grace_ArenaBoss
{
	GENERATED_BODY()


protected:
	AEnemy_WeaponMaster();
	virtual void LightAttack()override;
	UFUNCTION()
	void Attack();
	virtual void GetOffMeMove()override ;

};
