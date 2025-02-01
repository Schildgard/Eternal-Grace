// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_WeaponSwing.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "WeaponComponent.h"
#include "Weapon.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"
#include "HitEffectData.h"


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
	if (!CurrentWeapon)
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

	Ignore.Add(PerformingActor);
	Ignore.Add(PerformingActor->WeaponComponent->GetCurrentWeapon());

	UKismetSystemLibrary::SphereTraceSingleForObjects(PerformingActor->world, Start, End, 5.0f, PerformingActor->WeaponComponent->ObjectTypes, false, Ignore, EDrawDebugTrace::ForDuration, Hit, true);
	if (Hit.bBlockingHit)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(PerformingActor->world, PerformingActor->WeaponComponent->GetWeaponSparks(), Hit.Location, FRotator(Hit.ImpactNormal.X, 0.0f, 0.0f));

		//THIS SECTION IS AN ATTEMPT TO MOVE THE HIT EFFECT TO THE SPHERE TRACING. HOW EVER I MUST SOMEHOW FIND A WAY TO CHECK IF THE ATTACK WAS BLOCKED,
		// WHICH IS BY NY CALCULATED IN THE DEAL DAMAGE FUNCTION WHICH TRIGGERS ON OVERLAP COLLISION
		
	//	AEternal_Grace_ArenaCharacter* Char = Cast<AEternal_Grace_ArenaCharacter>(Hit.GetActor());
	//	if (Char)
	//	{
	//		UE_LOG(LogTemp, Warning, TEXT("Hit Character"))
	//			UPhysicalMaterial* PhysicalMaterial = Char->PhysicalMaterial;
	//		if (PhysicalMaterial)
	//		{
	//
	//			//CREATE A CONTEXT STRING
	//			static const FString ContextString(TEXT("Hit Effect Context"));
	//			FName MaterialName = FName(*PhysicalMaterial->GetName());
	//			//GONNA CHECK WHAT CONTEXT STRING PARAMETER DOES
	//			FHitEffectData* EffectData = PerformingActor->WeaponComponent->GetHitEffectDataTable()->FindRow<FHitEffectData>(MaterialName, ContextString);
	//
	//			if (EffectData)
	//			{
	//				UE_LOG(LogTemp, Warning, TEXT("PhysicalMaterial is : %s"), *MaterialName.ToString());
	//				if (EffectData->HitSound)
	//				{
	//					UGameplayStatics::PlaySoundAtLocation(PerformingActor->world, EffectData->HitSound, Hit.Location);
	//				}
	//				if (EffectData->NiagaraEffect)
	//				{
	//					UNiagaraFunctionLibrary::SpawnSystemAtLocation(PerformingActor->world, EffectData->NiagaraEffect, Hit.Location, FRotator(Hit.ImpactNormal.X, 0.0f, 0.0f));
	//				}
	//			}
	//			else
	//			{
	//				UE_LOG(LogTemp, Warning, TEXT("No effects found for PhysicalMaterial: %s"), *MaterialName.ToString());
	//			}
	//
	//		}
	//	}
	//	else
	//	{
		//	UNiagaraFunctionLibrary::SpawnSystemAtLocation(PerformingActor->world, PerformingActor->WeaponComponent->GetWeaponSparks(), Hit.Location, FRotator(Hit.ImpactNormal.X, 0.0f, 0.0f));

	//	}
	}

	//TODO PROBABLY IMPLEMENT DEAL DAMAGE HERE AS WELL ?
}
