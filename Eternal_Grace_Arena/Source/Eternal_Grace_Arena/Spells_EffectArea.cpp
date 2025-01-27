// Fill out your copyright notice in the Description page of Project Settings.


#include "Spells_EffectArea.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Eternal_Grace_ArenaCharacter.h"

void ASpells_EffectArea::BeginPlay()
{
		Super::BeginPlay();
		HitBox->OnComponentEndOverlap.AddDynamic(this, &ASpells_EffectArea::RemoveFromEffectList);
}

void ASpells_EffectArea::Tick(float DeltaSeconds)
{

	if (AffectedCharacters.Num() >= 1)
	{
		for (AEternal_Grace_ArenaCharacter* AffectedTarget : AffectedCharacters)
		{
			II_Damageable::Execute_GetDamage(AffectedTarget, (DamageValue * DeltaSeconds), 0,0, EStaggeringType::NoStagger, InstigatingActor, false);
		}
	}
}

void ASpells_EffectArea::SpellEffect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AEternal_Grace_ArenaCharacter* EnteringCharacter = Cast<AEternal_Grace_ArenaCharacter>(OtherActor);

	if (EnteringCharacter && EnteringCharacter->IsA(ValidCharacterClass))
	{
		AffectedCharacters.AddUnique(EnteringCharacter);
	}
}

void ASpells_EffectArea::RemoveFromEffectList(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	AEternal_Grace_ArenaCharacter* EnteringCharacter = Cast<AEternal_Grace_ArenaCharacter>(OtherActor);

	if (EnteringCharacter && AffectedCharacters.Contains(EnteringCharacter))
	{
		AffectedCharacters.Remove(EnteringCharacter);
	}
}
