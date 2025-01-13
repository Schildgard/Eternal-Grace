// Fill out your copyright notice in the Description page of Project Settings.


#include "Spells_Projectile.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include "Eternal_Grace_ArenaCharacter.h"
#include "ShieldComponent.h"
#include "CharacterAnimInstance.h"
#include "Kismet/GameplayStatics.h"


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

void ASpells_Projectile::DealDamage(AEternal_Grace_ArenaCharacter* Target)
{
	//CHECK IF PROJECTILE WAS BLOCKED
	bool AttackWasBlocked = false;
	float DamageDirection = CalculateAttackAngle(Target);
	if (Target->ShieldComponent && Target->ShieldComponent->GetCurrentShield())
	{
		if (Target->CharacterAnimationInstance->isGuarding)
		{
			if (DamageDirection <= 135.0f || DamageDirection >= 180.0f)
			{
				AttackWasBlocked = true;
			}
		}
	}

	if (Target->Implements<UI_Damageable>())
	{
	II_Damageable::Execute_GetDamage(Target, DamageValue, PoiseDamage, DamageDirection, EStaggeringType::NormalStagger, InstigatingActor, AttackWasBlocked);
	}
	if (HitSFX)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), HitSFX, Target->GetActorLocation());
	}
}


