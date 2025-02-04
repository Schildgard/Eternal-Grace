// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_ChargedWeaponSwing.h"
#include "PlayerCharacter.h"
#include "WeaponComponent.h"
#include "Weapon.h"

//THE DIFFERENCE BETWEEN THE CHARGED SWING AND THE NORMAL SWING IS, THAT THE CHARGED ONE ADDS THE PLAYERS CURRENT CHARGE POWER TO ITS DMG MULTIPLIER
void UNS_ChargedWeaponSwing::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{

	if (PlayerActor == nullptr)
	{
		PlayerActor = Cast<APlayerCharacter>(MeshComp->GetOwner());
		if (!PlayerActor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Charged WeaponSwing could not Cast into Player character"))
				return;
		}
	}

	AWeapon* CurrentWeapon = PlayerActor->WeaponComponent->GetCurrentWeapon();
	if(!CurrentWeapon)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not get current weapon"))
		return;
	}

	DamageMultiplier = (DamageMultiplier * PlayerActor->currentChargePower);
	if (DamageMultiplier <= 1.0f)
	{
		DamageMultiplier = 1.0f;
	}
}

void UNS_ChargedWeaponSwing::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	if (PlayerActor == nullptr)
	{
		PlayerActor = Cast < APlayerCharacter>(MeshComp->GetOwner());
		if (!PlayerActor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Charged WeaponSwing could not Cast into Player character"))
				return;
		}
	}
		Super::NotifyEnd(MeshComp, Animation, EventReference);
		PlayerActor->currentChargePower = 1.0f;
}
