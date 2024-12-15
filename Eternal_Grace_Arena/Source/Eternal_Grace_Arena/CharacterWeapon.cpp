// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterWeapon.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "HealthComponent.h"

UCharacterWeapon::UCharacterWeapon()
{
	SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Values.BaseDamage = 50.0f;
	Values.PoiseDamage = 20.0f;
	Values.StaminaCost = 15.0f;
	WeaponOwner = nullptr;
}

void UCharacterWeapon::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TODO: ACTUALLY IT IS BETTER TO DO THIS IN INITIALIZATION LIKE BEGIN PLAY
	if (WeaponOwner == nullptr)
	{
		WeaponOwner = GetOwner();
		UE_LOG(LogTemp, Warning, TEXT("GOT WEAPON OWNER"))
	}

	AEternal_Grace_ArenaCharacter* TargetActor = Cast<AEternal_Grace_ArenaCharacter>(OtherActor);
	// CHECK IF OVERLAPPING ACTOR IS AN CHARACTER
	if (TargetActor != WeaponOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("YOU HITTED A CHARACTER: %s"), *OtherActor->GetName());

		// CHECK IF HITTED ACTOR HAS AN HEALTH COMPONENT
		if (TargetActor->HealthComponent)
		{
			HittedActors.AddUnique(TargetActor);
		}


	}
	else if (OtherActor != WeaponOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("YOU HITTED A NON VIABLE TARGET: %s"), *OtherActor->GetName());
	}

}

void UCharacterWeapon::DealDamage(AEternal_Grace_ArenaCharacter* Target, float DamageMultiplier, EStaggeringType Staggertype)
{
	float Damage = Values.BaseDamage * DamageMultiplier;
	Target->HealthComponent->GetDamage(Damage, Values.PoiseDamage, Staggertype);
}

void UCharacterWeapon::HitDetect(float DamageMultiplier, EStaggeringType Staggertype)
{
	if (HittedActors.Num() > 0)
	{
		for (AEternal_Grace_ArenaCharacter* Target : HittedActors)
		{
			DealDamage(Target, DamageMultiplier, Staggertype);
		}
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("HITTED ACTORS ARE ZERO"))

}




