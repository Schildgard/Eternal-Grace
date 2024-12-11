// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "NotifyState_WeaponSwing.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UNotifyState_WeaponSwing : public UAnimNotifyState
{
	GENERATED_BODY()
	UNotifyState_WeaponSwing();

 virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)override;
// virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference);
 virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	AActor* OwningActor;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	AEternal_Grace_ArenaCharacter* PerformingActor;

};
