// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "NS_ContinousRecourceConsumption.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UNS_ContinousRecourceConsumption : public UAnimNotifyState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	float RessourceToConsume;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	float ConsumptionRate;


public:
	UFUNCTION()
	void ConsumeRessource();
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference) override;
};
