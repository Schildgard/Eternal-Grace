// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "StaggeringType.h"
#include "NS_WeaponSwing.generated.h"

/**
 * 
 */
class AEternal_Grace_ArenaCharacter;
UCLASS()
class ETERNAL_GRACE_ARENA_API UNS_WeaponSwing : public UAnimNotifyState
{
	GENERATED_BODY()
	UNS_WeaponSwing();

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	EStaggeringType StaggerType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	float DamageMultiplier;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	AActor* OwningActor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	AEternal_Grace_ArenaCharacter* PerformingActor;
};
