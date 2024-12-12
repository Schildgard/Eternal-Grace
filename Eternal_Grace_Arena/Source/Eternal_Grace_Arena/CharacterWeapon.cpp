// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterWeapon.h"
#include "Eternal_Grace_ArenaCharacter.h"

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
	if(WeaponOwner == nullptr)
	{
		WeaponOwner = GetOwner();
	}
	if (Cast<AEternal_Grace_ArenaCharacter>(OtherActor) && OtherActor != WeaponOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("YOU HITTED A ACTOR: %s"), *OtherActor->GetName());
	}
	else if (OtherActor != WeaponOwner)
	{
		UE_LOG(LogTemp, Warning, TEXT("YOU HITTED A NON VIABLE TARGET: %s"), *OtherActor->GetName());
	}
}


