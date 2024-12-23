// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterWeapon.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "HealthComponent.h"
#include "EternalGrace_BaseActor.h"
#include "HitEffectData.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "CharacterAnimInstance.h"
#include "CharacterShield.h"

UCharacterWeapon::UCharacterWeapon()
{
	SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Values.BaseDamage = 50.0f;
	Values.PoiseDamage = 20.0f;
	Values.StaminaCost = 15.0f;
	WeaponOwner = nullptr;
	HitEffectDataTable = nullptr;
	//DEFAULT CONSTRUCTOR VALUES. WHILE ATTACKING THEY ARE TEMPORARILY OVERWRITTEN BY NOTIFY VALUES
	StaggerType = EStaggeringType::NormalStagger;
	DamageMultiplier = 1.0f;
}

void UCharacterWeapon::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: ACTUALLY IT IS BETTER TO DO THIS IN INITIALIZATION LIKE BEGIN PLAY
	if (WeaponOwner == nullptr)
	{
		WeaponOwner = GetOwner();
		UE_LOG(LogTemp, Warning, TEXT("GOT WEAPON OWNER"))
	}

	//TEST
	//UStaticMeshComponent* HittedStaticMesh;

	AEternal_Grace_ArenaCharacter* TargetActor = Cast<AEternal_Grace_ArenaCharacter>(OtherActor);
	// CHECK IF OVERLAPPING ACTOR IS AN CHARACTER
	if (TargetActor && TargetActor != WeaponOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("YOU HITTED A CHARACTER: %s"), *OtherActor->GetName());

		// CHECK IF HITTED ACTOR HAS AN HEALTH COMPONENT
		if (TargetActor->HealthComponent && HittedActors.Contains(TargetActor) == false)
		{
			DealDamage(TargetActor);
			HittedActors.AddUnique(TargetActor);
		}
	}
	else if (TargetActor == nullptr) //if hitted Actor is no Character, check if it is an BaseActor
	{
		AEternalGrace_BaseActor* HittedObject = Cast<AEternalGrace_BaseActor>(OtherActor);
		if (HittedObject)
		{
			if (HittedObject->PhysicalMaterial)
			{
				ApplyHitEffect(HittedObject->PhysicalMaterial);
			}
		}
	}

}

void UCharacterWeapon::DealDamage(AEternal_Grace_ArenaCharacter* Target)
{
	float Damage = Values.BaseDamage * DamageMultiplier;
	float DamageDirection = CalculateAttackAngle(Target);


	if (Target->Shield && Target->CharacterAnimationInstance->isGuarding && DamageDirection <= 45.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("BLOCK"))
		Target->HealthComponent->BlockDamage(Damage, 0.0f,DamageDirection, StaggerType, Cast<AEternal_Grace_ArenaCharacter>(WeaponOwner)); //CHANGE THIS CAST LATER TO FIXED VARIABLE
		if (Target->Shield->PhysicalMaterial)
		{
			ApplyHitEffect(Target->Shield->PhysicalMaterial);
		}
		return;
	}
	//Target->CharacterAnimationInstance->isGuarding = false; //When Character is attacked from behind, he loses his guard. It is probably better to give HealthComponent an additional GetChipDamage Function, so the Weapon does not influence the AnimationInstance of a character
	Target->HealthComponent->GetDamage(Damage, Values.PoiseDamage, DamageDirection, StaggerType, Cast<AEternal_Grace_ArenaCharacter>(WeaponOwner));
	ApplyHitEffect(Target->PhysicalMaterial);
}

void UCharacterWeapon::ApplyHitEffect(UPhysicalMaterial* PhysicalMaterial)
{
	if (!PhysicalMaterial || !HitEffectDataTable)
	{
		UE_LOG(LogTemp, Warning, TEXT("No PhysicalMaterial or DataTable assigned!"));
		return;
	}
	//CREATE A CONTEXT STRING
	static const FString ContextString(TEXT("Hit Effect Context"));
	FName MaterialName = FName(*PhysicalMaterial->GetName());
	//GONNA CHECK WHAT CONTEXT STRING PARAMETER DOES
	FHitEffectData* EffectData = HitEffectDataTable->FindRow<FHitEffectData>(MaterialName, ContextString);

	if (EffectData)
	{
		if (EffectData->HitSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, EffectData->HitSound, GetOwner()->GetActorLocation());
		}
		if (EffectData->NiagaraEffect)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, EffectData->NiagaraEffect, GetOwner()->GetActorLocation());
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No effects found for PhysicalMaterial: %s"), *MaterialName.ToString());
	}
}

void UCharacterWeapon::ResetAttackValues()
{
	StaggerType = EStaggeringType::NormalStagger; //CHANGE THIS TODO
	DamageMultiplier = 1.0f;
	HittedActors.Empty();
}

float UCharacterWeapon::CalculateAttackAngle(AEternal_Grace_ArenaCharacter* Target)
{

	//CHECK DIRECTION
	FVector OwnerPosition = WeaponOwner->GetActorLocation();
	FVector TargetPosition = Target->GetActorLocation();
	FVector Direction = OwnerPosition - TargetPosition;
	Direction.Normalize(0.0001f);
	FVector ForwardDirectionOfTarget = Target->GetActorForwardVector();
	float DotProduct = UKismetMathLibrary::Dot_VectorVector(Direction, ForwardDirectionOfTarget);
	float Degrees = UKismetMathLibrary::DegAcos(DotProduct);
	return Degrees;

}




