// Fill out your copyright notice in the Description page of Project Settings.


#include "Damage_Spells.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "NiagaraFunctionLibrary.h"
#include "HealthComponent.h"

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

	if (HitSFX)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), HitSFX, Target->GetActorLocation());
	}
	AEternal_Grace_ArenaCharacter* Caster = Cast<AEternal_Grace_ArenaCharacter>(GetInstigator()); //BULLSHIT CODE. NEED TO REFACTOR HEALTH COMPONENT
	if (Caster)
	{
	//	Target->GetDamage(DamageValue, PoiseDamage, HitAngle, EStaggeringType::NormalStagger, Caster);
	}
	else UE_LOG(LogTemp, Warning, TEXT("Caster could not be casted to a Eternal grace Character"))

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
