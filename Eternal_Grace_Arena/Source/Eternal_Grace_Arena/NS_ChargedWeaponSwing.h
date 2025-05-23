// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NS_WeaponSwing.h"
#include "NS_ChargedWeaponSwing.generated.h"

/**
 *
 */
//class AEternal_Grace_ArenaCharacter;
class APlayerCharacter;
UCLASS()
class ETERNAL_GRACE_ARENA_API UNS_ChargedWeaponSwing : public UNS_WeaponSwing
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	APlayerCharacter* PlayerActor;

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)override;

};
