// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "NS_RotateTowardsTarget.generated.h"

/**
 * 
 */
class AEternal_Grace_ArenaEnemy;
UCLASS()
class ETERNAL_GRACE_ARENA_API UNS_RotateTowardsTarget : public UAnimNotify
{
	GENERATED_BODY()
	UNS_RotateTowardsTarget();
protected:
UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
AEternal_Grace_ArenaEnemy* PerformingActor;
virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
