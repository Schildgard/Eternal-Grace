// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Engine/StaticMeshActor.h"
#include "Components/CapsuleComponent.h"

AWeapon::AWeapon()
{
	Stats = { 50.0f,20.0f,15.0f };
	//Stats.BaseDamage = 50.0f;
	//Stats.PoiseDamage = 20.0f;
	//Stats.StaminaCost = 15.0f;
	ColliderComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Hitbox"));
	
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
}

FWeaponStats AWeapon::GetWeaponStats()
{
	return Stats;
}

FTransform AWeapon::GetSocket(FName SocketName)
{
	if (GetMesh() && GetMesh()->DoesSocketExist(SocketName))
	{
		UE_LOG(LogTemp, Warning, TEXT("Success"))
			return GetMesh()->GetSocketTransform(SocketName);
	}
	UE_LOG(LogTemp, Warning, TEXT("Fail"))
		return FTransform::Identity;
}

UCapsuleComponent* AWeapon::GetColliderShape()
{
	return ColliderComponent;
}

