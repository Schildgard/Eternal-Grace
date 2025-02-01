// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_WeaponSwing.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "WeaponComponent.h"
#include "Weapon.h"
#include "Kismet/KismetSystemLibrary.h"
#include "NiagaraFunctionLibrary.h"


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
	//TRY HERE TO SPAWN NIAGARA
	TArray<AActor*> Ignore;
	FHitResult Hit;
	//PerformingActor->WeaponComponent->GetCurrentWeapon()->GetSocket("weaponStart");
	//PerformingActor->WeaponComponent->GetCurrentWeapon()->GetSocket("weaponEnd");
	FVector Start = PerformingActor->WeaponComponent->GetCurrentWeapon()->GetMesh()->GetSocketLocation("weaponStart");
	FVector End = PerformingActor->WeaponComponent->GetCurrentWeapon()->GetMesh()->GetSocketLocation("weaponEnd");

	Ignore.Add(PerformingActor);
	Ignore.Add(PerformingActor->WeaponComponent->GetCurrentWeapon());

	//UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), Start, End, 5.0f, PerformingActor->WeaponComponent->ObjectTypes, false,Ignore,EDrawDebugTrace::None,Hit,true);

	UKismetSystemLibrary::SphereTraceSingleForObjects(PerformingActor->world, Start, End, 5.0f, PerformingActor->WeaponComponent->ObjectTypes, false, Ignore, EDrawDebugTrace::ForDuration, Hit, true);
	if (Hit.bBlockingHit)
	{
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(PerformingActor->world, PerformingActor->WeaponComponent->GetWeaponSparks(), Hit.Location, FRotator(Hit.ImpactNormal.X, 0.0f, 0.0f));
		UE_LOG(LogTemp, Warning, TEXT("Hitted : %s"), *Hit.GetActor()->GetName())
	}
}
