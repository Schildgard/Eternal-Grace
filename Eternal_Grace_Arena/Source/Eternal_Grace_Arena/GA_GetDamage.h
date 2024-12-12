// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility_Montage.h"
#include "GA_GetDamage.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UGA_GetDamage : public UGameplayAbility_Montage
{
	GENERATED_BODY()
	UGA_GetDamage() {};

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess))
	//UAnimMontage* HitReaction;

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;
	
};
