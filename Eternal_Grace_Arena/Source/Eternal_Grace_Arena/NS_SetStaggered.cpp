// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_SetStaggered.h"
#include "HAL/CriticalSection.h"

static FCriticalSection CriticalSection;

UNS_SetStaggered::UNS_SetStaggered()
{
	Owner = nullptr;
}
void UNS_SetStaggered::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	FScopeLock Lock(&CriticalSection);
	if (Owner == nullptr)
	{
		Owner = Cast<AEternal_Grace_ArenaCharacter>(MeshComp->GetOwner());
		if (Owner)
		{
			Owner->CharacterAnimationInstance->isAttacking = false;
			Owner->CharacterAnimationInstance->isStaggered = true;
			UE_LOG(LogTemp, Warning, TEXT("SetStaggerd Notify set its owner"))
		}
	}
	else if (IsValid(Owner->CharacterAnimationInstance))
	{
		UE_LOG(LogTemp, Warning, TEXT("SetStaggered and Attacking"))
		Owner->CharacterAnimationInstance->isAttacking = false;
		Owner->CharacterAnimationInstance->isStaggered = true; // STRANGE ERROR OOCURS SOMETIMES IN THIS LINE
	}
}

void UNS_SetStaggered::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (Owner != nullptr)
	{
		if (Owner->CharacterAnimationInstance != nullptr)
		{
			Owner->CharacterAnimationInstance->isStaggered = false;
		}
	}
}
