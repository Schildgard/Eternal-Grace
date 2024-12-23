// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_SetStaggered.h"

UNS_SetStaggered::UNS_SetStaggered()
{
	Owner = nullptr;
}
void UNS_SetStaggered::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	if (Owner == nullptr)
	{
		Owner = Cast<AEternal_Grace_ArenaCharacter>(MeshComp->GetOwner());
	}
	else if (Owner->CharacterAnimationInstance)
	{
		Owner->CharacterAnimationInstance->isStaggered = true;
	}
}

void UNS_SetStaggered::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (Owner)
	{
		if (Owner->CharacterAnimationInstance)
		{
			Owner->CharacterAnimationInstance->isStaggered = false;
		}
	}
}
