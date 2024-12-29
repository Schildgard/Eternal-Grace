// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_ChargedWeaponSwing.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "CharacterWeapon.h"

//THE DIFFERENCE BETWEEN THE CHARGED SWING AND THE NORMAL SWING IS, THAT THE CHARGED ONE ADDS THE PLAYERS CURRENT CHARGE POWER TO ITS DMG MULTIPLIER
void UNS_ChargedWeaponSwing::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	//THIS SHOULDNT BE DONE ON EVERY NOTIFY BEGIN, BUT ON INITIALIZATION
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
	PerformingActor->Weapon->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	PerformingActor->Weapon->DamageMultiplier = (DamageMultiplier * PerformingActor->currentChargePower);
	if (PerformingActor->Weapon->DamageMultiplier <= 1.0f)
	{
		PerformingActor->Weapon->DamageMultiplier = 1.0f;
	}
	PerformingActor->Weapon->StaggerType = StaggerType;
}

void UNS_ChargedWeaponSwing::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (PerformingActor != nullptr)
	{
		Super::NotifyEnd(MeshComp, Animation, EventReference);
		PerformingActor->currentChargePower = 1.0f;

	}
}
