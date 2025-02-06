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

