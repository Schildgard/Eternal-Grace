// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify_PlaySound.h"
#include "AnimNotify_PlayRandomSound.generated.h"

/**
 *
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API UAnimNotify_PlayRandomSound : public UAnimNotify_PlaySound
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimNotify", meta = (ExposeOnSpawn = true))
	TArray<TObjectPtr<USoundBase>> Sounds;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimNotify", meta = (ExposeOnSpawn = true))
	float ScanDistance = 200.0f;
public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
public:
	UPhysicalMaterial* CheckGroundMaterial(USkeletalMeshComponent* MeshComp);

};
