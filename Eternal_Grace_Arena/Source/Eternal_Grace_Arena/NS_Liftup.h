// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "NS_Liftup.generated.h"

/**
 * 
 */
class AEternal_Grace_ArenaCharacter;
UCLASS()
class ETERNAL_GRACE_ARENA_API UNS_Liftup : public UAnimNotify
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess))
	AEternal_Grace_ArenaCharacter* PerformingActor;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference);
	
};
