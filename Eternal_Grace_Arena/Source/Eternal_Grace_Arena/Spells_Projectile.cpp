// Fill out your copyright notice in the Description page of Project Settings.


#include "Spells_Projectile.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include "Eternal_Grace_ArenaCharacter.h"
#include "ShieldComponent.h"
#include "CharacterAnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet//KismetMathLibrary.h"
#include "Enemy_MageBoss.h" //BULLSHIT CODE
#include "SpellComponent.h" //ALSO BULLSHIT


ASpells_Projectile::ASpells_Projectile()
{
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	Movement->InitialSpeed = 1000.0f;
	Movement->MaxSpeed = 1000.0f;
	Movement->ProjectileGravityScale = 0.0f;
	Movement->bIsHomingProjectile = false;
}

void ASpells_Projectile::SetDirection(AEternal_Grace_ArenaCharacter* Target)
{

	FVector InstigatorLocation = InstigatingActor->GetActorLocation();
	FVector TargetLocation = Target->GetActorLocation();
	FVector TargetDirection = (TargetLocation - InstigatorLocation);
	if (TargetDirection.Normalize())
	{
		Direction = TargetDirection;
	}
	else
	{
		Direction = GetActorForwardVector();
	}
}

void ASpells_Projectile::BeginPlay()
{
	Super::BeginPlay();
	//BULLSHIT CODE. GetSpellComponent should not be exclusive to boss. If I can check on every character if he has an spellcomponent, I dont need to cast into the mage boss here
	AEnemy_MageBoss* Caster = Cast<AEnemy_MageBoss>(InstigatingActor);
	if (Caster)
	{
		SetDirection(Caster->GetSpellComponent()->GetTarget());
		Movement->Velocity = (Direction * Movement->InitialSpeed);
	}
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


void ASpells_Projectile::SpellEffect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::SpellEffect(OverlappedComponent, OtherActor, OtherComponent, OtherBodyIndex, bFromSweep, SweepResult);

	if (OtherActor && OtherActor->IsA(ValidCharacterClass))
	{
		Destroy(); //CHANGE THIS, SO THE VALID CHARACTER CHECK IS DONE IN VERY BASE CLASS
	}
}


