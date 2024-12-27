// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "NS_CancelMontage.generated.h"

/**
 * 
 */
class AEternal_Grace_ArenaCharacter;
class AEternal_Grace_ArenaEnemy;
UCLASS()
class ETERNAL_GRACE_ARENA_API UNS_CancelMontage : public UAnimNotify
{
	GENERATED_BODY()

	UNS_CancelMontage();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	AEternal_Grace_ArenaEnemy* PerformingActor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	float BlendOutTime;


	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
