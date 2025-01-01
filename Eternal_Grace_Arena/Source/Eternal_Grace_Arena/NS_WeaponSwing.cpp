// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_WeaponSwing.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "CharacterWeapon.h"


UNS_WeaponSwing::UNS_WeaponSwing()
{
	PerformingActor = nullptr;
	OwningActor = nullptr;

	StaggerType = EStaggeringType::NormalStagger;
	DamageMultiplier = 1.0f;
}
void UNS_WeaponSwing::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	//THIS SHOULDNT BE DONE ON EVERY NOTIFY BEGIN, BUT ON INITIALIZATION
	if (PerformingActor == nullptr)
	{
		PerformingActor = Cast<AEternal_Grace_ArenaCharacter>(MeshComp->GetOwner());
		if (PerformingActor)
		{
		//	UE_LOG(LogTemp, Warning, TEXT("Owner Found"))
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Owner NOT Found"))
				return;
		}
	}
	PerformingActor->Weapon->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	PerformingActor->Weapon->DamageMultiplier = DamageMultiplier;
	PerformingActor->Weapon->StaggerType = StaggerType;
}


void UNS_WeaponSwing::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (PerformingActor)
	{
		PerformingActor->Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		PerformingActor->Weapon->ResetAttackValues();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Owner NOT Found"))
			return;
	}
}
