// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Engine/StaticMeshActor.h"

AWeapon::AWeapon()
{
	Stats = { 50.0f,20.0f,15.0f };
	//Stats.BaseDamage = 50.0f;
	//Stats.PoiseDamage = 20.0f;
	//Stats.StaminaCost = 15.0f;
	DamageMultiplier = 1.0f;
	
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
//	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
//	Mesh->SetCollisionResponseToAllChannels(ECR_Overlap);
}

FWeaponStats AWeapon::GetWeaponStats()
{
	return Stats;
}

