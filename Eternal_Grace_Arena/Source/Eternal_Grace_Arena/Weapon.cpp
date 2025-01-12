// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Engine/StaticMeshActor.h"

AWeapon::AWeapon()
{
	BaseDamage = 50.0f;
	PoiseDamage = 20.0f;
	StaminaCost = 15.0f;
	
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetCollisionResponseToAllChannels(ECR_Overlap);
}

FWeaponStats AWeapon::GetWeaponStats()
{
	return Stats;
}

