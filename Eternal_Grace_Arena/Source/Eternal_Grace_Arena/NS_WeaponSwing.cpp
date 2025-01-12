// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_WeaponSwing.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "CharacterWeapon.h"
#include "WeaponComponent.h"
#include "Weapon.h"


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
	if (!PerformingActor)
	{
		PerformingActor = Cast<AEternal_Grace_ArenaCharacter>(MeshComp->GetOwner());
		if (!PerformingActor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Owner NOT Found"))
				return;
		}
	}

	AWeapon* CurrentWeapon = PerformingActor->WeaponComponent->GetCurrentWeapon();
	if(!CurrentWeapon)
	{
		UE_LOG(LogTemp, Error, TEXT("WeaponSwing Notify of %s could not get CurrentWeapon from WeaponCOmponent"), *PerformingActor->GetName())
			return;
	}
	CurrentWeapon->GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CurrentWeapon->DamageMultiplier = DamageMultiplier;
	PerformingActor->WeaponComponent->SetStaggerType(StaggerType);
}


void UNS_WeaponSwing::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (!PerformingActor)
	{
		PerformingActor = Cast<AEternal_Grace_ArenaCharacter>(MeshComp->GetOwner());
		if (!PerformingActor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Owner NOT Found"))
				return;
		}
	}
//	PerformingActor->Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
//	PerformingActor->Weapon->ResetAttackValues();
//	PerformingActor->Weapon->StaggerType = EStaggeringType::NormalStagger;
	AWeapon* CurrentWeapon = PerformingActor->WeaponComponent->GetCurrentWeapon();
	if (!CurrentWeapon)
	{
		UE_LOG(LogTemp, Error, TEXT("WeaponSwing Notify of %s could not get CurrentWeapon from WeaponCOmponent"), *PerformingActor->GetName())
			return;
	}
	CurrentWeapon->GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);	
	PerformingActor->WeaponComponent->ResetAttackValues();
	PerformingActor->WeaponComponent->SetStaggerType(EStaggeringType::NormalStagger);
}
