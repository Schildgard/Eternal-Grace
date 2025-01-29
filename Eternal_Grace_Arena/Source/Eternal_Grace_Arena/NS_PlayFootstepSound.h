// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify_PlaySound.h"
#include "NS_PlayFootstepSound.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UNS_PlayFootstepSound : public UAnimNotify_PlaySound
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimNotify", meta = (ExposeOnSpawn = true))
	TArray<TObjectPtr<USoundBase>> Sounds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimNotify", meta = (ExposeOnSpawn = true))
	float ScanDistance = 10.0f;
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
	UPhysicalMaterial* CheckGroundMaterial(USkeletalMeshComponent* MeshComp);
	
};
