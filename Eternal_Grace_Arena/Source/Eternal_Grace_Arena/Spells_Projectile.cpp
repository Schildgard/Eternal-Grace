// Fill out your copyright notice in the Description page of Project Settings.


#include "Spells_Projectile.h"
#include <GameFramework/ProjectileMovementComponent.h>



ASpells_Projectile::ASpells_Projectile()
{
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	Movement->InitialSpeed = 100.0f;
	Movement->MaxSpeed = 100.0f;
	Movement->ProjectileGravityScale = 0.0f;
	Movement->bIsHomingProjectile = false;
	Direction = GetActorForwardVector();
}

void ASpells_Projectile::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

