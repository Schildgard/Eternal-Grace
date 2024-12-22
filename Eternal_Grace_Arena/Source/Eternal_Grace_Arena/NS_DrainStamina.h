// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "NS_DrainStamina.generated.h"

/**
 * 
 */
class APlayerCharacter;
UCLASS()
class ETERNAL_GRACE_ARENA_API UNS_DrainStamina : public UAnimNotify
{
	GENERATED_BODY()
	
	UNS_DrainStamina();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	AActor* OwningActor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	APlayerCharacter* PerformingActor;
	//DIFFERENT ANIMATIONS CONSUME ADDITIONAL STAMINA, WHICH IS REGULATED BY THIS NOTIFY AS WELL
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	float ConsumptionMultiplier;
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
	
};
