// Fill out your copyright notice in the Description page of Project Settings.


#include "Spells_HomingProjectile.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include <GameFramework/ProjectileMovementComponent.h>


ASpells_HomingProjectile::ASpells_HomingProjectile(AEternal_Grace_ArenaCharacter* LockedOnTarget)
{
	Movement->bIsHomingProjectile = true;
	Target = LockedOnTarget;
}
void ASpells_HomingProjectile::BeginPlay()
{
	Super::BeginPlay();
	if(Target)
	{
		Movement->HomingTargetComponent = Target->GetRootComponent();
	}
		UE_LOG(LogTemp, Warning, TEXT("Spell was castet for %f Damage"), DamageValue)
}
