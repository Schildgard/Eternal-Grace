// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponComponent.h"
#include "Weapon.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Kismet//KismetMathLibrary.h"
#include "Kismet//GameplayStatics.h"
#include "HitEffectData.h"
#include "NiagaraSystem.h"
#include "CharacterAnimInstance.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	WeaponOwner = nullptr;
	EquippedWeapon = nullptr;
	HitEffectDataTable = nullptr;
	WeaponSparks = nullptr;
	WeaponTrail = nullptr;

}


void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	WeaponOwner = GetOwner();
	OwningCharacter = Cast<AEternal_Grace_ArenaCharacter>(WeaponOwner);
	if (!WeaponOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get WeaponOwner for %s"), *GetName())
			return;
	}

	if (!EquippedWeaponClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get Equipped Weapon Class for %s"), *GetName())
			return;
	}

	EquippedWeapon = GetWorld()->SpawnActor<AWeapon>(EquippedWeaponClass);
	if (!EquippedWeapon)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to Spawn Equipped Weapon Object for %s"), *GetName())
			return;
	}

	EquippedWeapon->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	UpdateCurrentMoveSet();
}



void UWeaponComponent::HeavyAttack()
{
	//When Heavy Attack Button is released from charge Position the Player Character unleashes his Heavy Attack 
//	if (OwningCharacter->CharacterAnimationInstance->isCharging)
//	{
//		OwningCharacter->CharacterAnimationInstance->isCharging = false; //LEAVE CHARGING STATE
//		OwningCharacter->CharacterAnimationInstance->isAttacking = true; //SET PLAYER IN ATTACK STATE, SO THE ANIMATION CAN NOT BE INTERUPTED BY A LIGHT ATTACK COMMAND
//		OwningCharacter->CharacterAnimationInstance->isInHeavyAttack = true; // SET PLAYER IN HEAVY ATTACK STATE, SO ANOTHER HEAVY ATTACK COMMAND TRIGGERS THE SECOND ATTACK ANIM
//		UE_LOG(LogTemp, Warning, TEXT("Character Releases Attack"))
//			OwningCharacter->PlayAnimMontage(CurrentHeavyAttacks[0], 1.0f);
//	}
//	else if (OwningCharacter->CharacterAnimationInstance->isInHeavyAttack)
//	{
//		//IF PLAYER IS IN HEAVY ATTACK, A SECOND HEAVY ATTACK COMMAND TRIGGERS THE FOLLOW UP ANIMATION
//		OwningCharacter->CharacterAnimationInstance->isInHeavyAttack = false;//LEAVE HEAVY ATTACK STATE, SO THE FOLLOW UP ANIMATION ONLY TRIGGERS ONCE
//		OwningCharacter->CharacterAnimationInstance->isAttacking = true; //SET IS ATTACKING TO TRUE TO MAKE SURE THE FOLLOW UP ANIMATION IS NOT CANCELED BY LIGHT ATTACK COMMAND
//		OwningCharacter->PlayAnimMontage(CurrentHeavyAttacks[1], 1.0f);
//		UE_LOG(LogTemp, Warning, TEXT("Character Already is not Charging"))
//	}
}

void UWeaponComponent::UpdateCurrentMoveSet()
{
	if(EquippedWeapon)
	{
	CurrentLightAttacks = EquippedWeapon->GetLightAttackMontages();
	CurrentHeavyAttacks = EquippedWeapon->GetHeavyAttackMontages();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Weapon Equipped"))
	}
}

float UWeaponComponent::CalculateAttackAngle(AActor* Target)
{
	FVector OwnerPosition = WeaponOwner->GetActorLocation();
	FVector TargetPosition = Target->GetActorLocation();
	FVector Direction = OwnerPosition - TargetPosition;
	Direction.Normalize(0.0001f);
	FVector ForwardDirectionOfTarget = Target->GetActorForwardVector();
	float DotProduct = UKismetMathLibrary::Dot_VectorVector(Direction, ForwardDirectionOfTarget);
	float Degrees = UKismetMathLibrary::DegAcos(DotProduct);
	return Degrees;
}

TArray<TEnumAsByte<EObjectTypeQuery>> UWeaponComponent::GetObjectTypes()
{
	return ObjectTypes;
}

AWeapon* UWeaponComponent::GetCurrentWeapon()
{
	return EquippedWeapon;
}

UNiagaraSystem* UWeaponComponent::GetWeaponTrail()
{
	return WeaponTrail;
}

UNiagaraSystem* UWeaponComponent::GetWeaponSparks()
{
	return WeaponSparks;
}

UDataTable* UWeaponComponent::GetHitEffectDataTable()
{
	return HitEffectDataTable;
}

TArray<UAnimMontage*> UWeaponComponent::GetCurrentLightAttacks()
{
	return CurrentLightAttacks;
}

TArray<UAnimMontage*> UWeaponComponent::GetCurrentHeavyAttacks()
{
	return CurrentHeavyAttacks;
}

