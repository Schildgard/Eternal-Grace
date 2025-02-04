// Fill out your copyright notice in the Description page of Project Settings.


#include "Damage_Spells.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "CharacterAnimInstance.h"
#include "ShieldComponent.h"
#include "HealthComponent.h"



ADamage_Spells::ADamage_Spells()
{
	DamageValue = 500.0f;
	PoiseDamage = 100.0f;
	HitSFX = nullptr;
	isBlockable = true;

	StaggerType = EStaggeringType::NormalStagger;

}

void ADamage_Spells::SpellEffect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::SpellEffect(OverlappedComponent, OtherActor, OtherComponent, OtherBodyIndex, bFromSweep, SweepResult);


	if (OtherActor && OtherActor->IsA(ValidCharacterClass))
	{
		AEternal_Grace_ArenaCharacter* HittedCharacter = Cast<AEternal_Grace_ArenaCharacter>(OtherActor);
		if (HittedCharacter)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s hitted"), *GetName(), *HittedCharacter->GetName())
				DealDamage(HittedCharacter);
			if (OnHitVFX)
			{
				UNiagaraFunctionLibrary::SpawnSystemAttached(OnHitVFX, OtherComponent, NAME_None, FVector(0.0f), FRotator(0.0f), EAttachLocation::KeepRelativeOffset, true);
			}
		}
	}
}

void ADamage_Spells::DealDamage(AEternal_Grace_ArenaCharacter* Target)
{
	float HitAngle = CalculateAttackAngle(Target);

	if(Target->Implements<UI_Damageable>())
	{
		if (!isBlockable)
		{
		II_Damageable::Execute_GetDamage(Target,DamageValue, PoiseDamage, HitAngle, StaggerType, InstigatingActor, false);//ONLY PROJECTILES CAN BE BLOCKED
		}
		else
		{
			bool AttackWasBlocked = false;
			if (Target->ShieldComponent && Target->ShieldComponent->GetCurrentShield())
			{
				if (Target->CharacterAnimationInstance->isGuarding)
				{
					if (HitAngle <= 135.0f || HitAngle >= 180.0f)
					{
						AttackWasBlocked = true;
					}
				}
			}

			II_Damageable::Execute_GetDamage(Target, DamageValue, PoiseDamage, HitAngle, StaggerType, InstigatingActor, AttackWasBlocked);//ONLY PROJECTILES CAN BE BLOCKED
		}


	}
	if (HitSFX)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), HitSFX, Target->GetActorLocation());
	}

}

//IS ALSO IN CHARACTER WEAPON CLASS
float ADamage_Spells::CalculateAttackAngle(AEternal_Grace_ArenaCharacter* Target)
{

	//CHECK DIRECTION
	FVector OwnerPosition = GetInstigator()->GetActorLocation();
	FVector TargetPosition = Target->GetActorLocation();
	FVector Direction = OwnerPosition - TargetPosition;
	Direction.Normalize(0.0001f);
	FVector ForwardDirectionOfTarget = Target->GetActorForwardVector();
	float DotProduct = UKismetMathLibrary::Dot_VectorVector(Direction, ForwardDirectionOfTarget);
	float Degrees = UKismetMathLibrary::DegAcos(DotProduct);
	return Degrees;

}
