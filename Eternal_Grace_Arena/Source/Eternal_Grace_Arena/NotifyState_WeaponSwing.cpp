// Fill out your copyright notice in the Description page of Project Settings.


#include "NotifyState_WeaponSwing.h"

#include "PlayerCharacter.h"

UNotifyState_WeaponSwing::UNotifyState_WeaponSwing()
{
	PerformingActor = nullptr;
}

void UNotifyState_WeaponSwing::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	if (PerformingActor == nullptr)
	{
		PerformingActor = Cast<AEternal_Grace_ArenaCharacter>(MeshComp->GetOwner());
		if (PerformingActor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Owner Found"))
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Owner NOT Found"))
				return;
		}
	}
	PerformingActor->WeaponComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void UNotifyState_WeaponSwing::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
if (PerformingActor)
{
	PerformingActor->WeaponComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//	UE_LOG(LogTemp, Warning, TEXT("Collsion Deactivated"))
}
else
{
	UE_LOG(LogTemp, Warning, TEXT("Owner NOT Found"))
		return;
}
}
