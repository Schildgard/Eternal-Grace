// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_WeaponSwing.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "WeaponComponent.h"
#include "Weapon.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "HitEffectData.h"
#include "ShieldComponent.h"
#include "Shield.h"
#include "CharacterAnimInstance.h"
#include "Components/CapsuleComponent.h"


UNS_WeaponSwing::UNS_WeaponSwing()
{
	PerformingActor = nullptr;
	OwningActor = nullptr;

	StaggerType = EStaggeringType::NormalStagger;
	DamageMultiplier = 1.0f;
}
void UNS_WeaponSwing::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	HittedActors.Empty();
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

	//AWeapon* CurrentWeapon = PerformingActor->WeaponComponent->GetCurrentWeapon();
	//if (!CurrentWeapon)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("WeaponSwing Notify of %s could not get CurrentWeapon from WeaponCOmponent"), *PerformingActor->GetName())
	//		return;
	//}
	//CurrentWeapon->GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	//CurrentWeapon->DamageMultiplier = DamageMultiplier;
	//PerformingActor->WeaponComponent->SetStaggerType(StaggerType);
}


void UNS_WeaponSwing::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	HittedActors.Empty();
	//	if (!PerformingActor)
	//	{
	//		PerformingActor = Cast<AEternal_Grace_ArenaCharacter>(MeshComp->GetOwner());
	//		if (!PerformingActor)
	//		{
	//			UE_LOG(LogTemp, Warning, TEXT("Owner NOT Found"))
	//				return;
	//		}
	//	}
	//
	//	AWeapon* CurrentWeapon = PerformingActor->WeaponComponent->GetCurrentWeapon();
	//	if (!CurrentWeapon)
	//	{
	//		UE_LOG(LogTemp, Error, TEXT("WeaponSwing Notify of %s could not get CurrentWeapon from WeaponCOmponent"), *PerformingActor->GetName())
	//			return;
	//	}
	//	CurrentWeapon->GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//	PerformingActor->WeaponComponent->ResetAttackValues();
	//	PerformingActor->WeaponComponent->SetStaggerType(EStaggeringType::NormalStagger);
}

void UNS_WeaponSwing::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
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
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	//SPHERE TRACE FOR HIT EFFECT
	TArray<AActor*> Ignore;
	FHitResult Hit;

	FVector Start = PerformingActor->WeaponComponent->GetCurrentWeapon()->GetMesh()->GetSocketLocation("weaponStart");
	FVector End = PerformingActor->WeaponComponent->GetCurrentWeapon()->GetMesh()->GetSocketLocation("weaponEnd");
	float CollisionRadius = PerformingActor->WeaponComponent->GetCurrentWeapon()->GetColliderShape()->GetScaledCapsuleRadius();

	Ignore.Add(PerformingActor);
	Ignore.Add(PerformingActor->WeaponComponent->GetCurrentWeapon());

	UKismetSystemLibrary::SphereTraceSingleForObjects(PerformingActor->world, Start, End, CollisionRadius, PerformingActor->WeaponComponent->ObjectTypes, false, Ignore, EDrawDebugTrace::None, Hit, true);

	if (Hit.bBlockingHit)
	{
		// 1. Check if Hitted Collider is part of a Character
		UPhysicalMaterial* PhysicalMaterial = nullptr;
		AActor* HittedActor = Hit.GetActor();
		AEternal_Grace_ArenaCharacter* Char = Cast<AEternal_Grace_ArenaCharacter>(HittedActor);
		if (Char)
		{
			//If so, Get his physical Material for Hit Effect, check if the attack is blocked, then apply damage and hit effect
			if (!HittedActors.Contains(HittedActor) && Char->Implements<UI_Damageable>())
			{
				HittedActors.AddUnique(Char);
				PhysicalMaterial = Char->PhysicalMaterial;
				AWeapon* EquippedWeapon = PerformingActor->WeaponComponent->GetCurrentWeapon();

				//CALCULATE DAMAGE PROPERTIES
				float Damage = EquippedWeapon->GetWeaponStats().BaseDamage * DamageMultiplier;
				float PoiseDamage = EquippedWeapon->GetWeaponStats().PoiseDamage * DamageMultiplier;;
				float DamageDirection = PerformingActor->WeaponComponent->CalculateAttackAngle(Char);
				bool AttackWasBlocked = false;

				//Check if Attack was blocked
				if (Char->ShieldComponent && Char->ShieldComponent->GetCurrentShield())
				{
					if (Char->CharacterAnimationInstance->isGuarding)
					{
						if (DamageDirection <= 135.0f || DamageDirection >= 180.0f)
						{
							AttackWasBlocked = true;
							PhysicalMaterial = Char->ShieldComponent->GetCurrentShield()->GetShieldStats().PhysicalMaterial;
						}
					}
				}
				II_Damageable::Execute_GetDamage(Char, Damage, PoiseDamage, DamageDirection, StaggerType, PerformingActor, AttackWasBlocked);
				//Apply Hit Effect
				if (PhysicalMaterial)
				{
					//Check if Physical Material is in HitEffect Data Table Struct. If not spawn default sparks
					static const FString ContextString(TEXT("Hit Effect Context"));
					FName MaterialName = FName(*PhysicalMaterial->GetName());
					FHitEffectData* EffectData = PerformingActor->WeaponComponent->GetHitEffectDataTable()->FindRow<FHitEffectData>(MaterialName, ContextString);
					if (EffectData)
					{
						ApplyHitEffect(*EffectData, Hit.Location, FRotator(Hit.ImpactNormal.X, Hit.ImpactNormal.Y, Hit.ImpactNormal.Z));
						return;
					}
				}
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(PerformingActor->world, PerformingActor->WeaponComponent->GetWeaponSparks(), Hit.Location, FRotator(Hit.ImpactNormal.X, 0.0f, 0.0f));
			}
		}
		else
		{
			// If hitted collider is not part of a character, also check for Hit Effect Data.
		   //The reason for this else Statement is, that the hit of a character should trigger a hit effect only once
		   // but is shouls trigger multiple hit effects when hitting environment
			if (PhysicalMaterial)
			{
				static const FString ContextString(TEXT("Hit Effect Context"));
				FName MaterialName = FName(*PhysicalMaterial->GetName());
				FHitEffectData* EffectData = PerformingActor->WeaponComponent->GetHitEffectDataTable()->FindRow<FHitEffectData>(MaterialName, ContextString);
				if (EffectData)
				{
					ApplyHitEffect(*EffectData, Hit.Location, FRotator(Hit.ImpactNormal.X, Hit.ImpactNormal.Y, Hit.ImpactNormal.Z));
				}
			}
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(PerformingActor->world, PerformingActor->WeaponComponent->GetWeaponSparks(), Hit.Location, FRotator(Hit.ImpactNormal.X, 0.0f, 0.0f));
		}
	}
}

void UNS_WeaponSwing::ApplyHitEffect(FHitEffectData EffectData, FVector HitLocation, FRotator HitRotation)
{
	if (EffectData.HitSound)
	{
		UGameplayStatics::PlaySoundAtLocation(PerformingActor->world, EffectData.HitSound, HitLocation);
	}
	if (EffectData.NiagaraEffect)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(PerformingActor->world, EffectData.NiagaraEffect, HitLocation, HitRotation);

	}
}
