// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ArenaEnemy_Caster.h"
#include "SpellComponent.h"
#include "Kismet/GameplayStatics.h"

AEternal_Grace_ArenaEnemy_Caster::AEternal_Grace_ArenaEnemy_Caster()
{
	SpellComponent = CreateDefaultSubobject<USpellComponent>("Spells");
	TestTimer = 5.0f;
	TestCountdown = TestTimer;
}

void AEternal_Grace_ArenaEnemy_Caster::CastSpell()
{
	if (SpellComponent)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = this;

		if (SpellComponent->SpellList.Num() > 0)
		{
			ASpell* SpellCast = GetWorld()->SpawnActor<ASpell>(SpellComponent->SpellList[0],GetActorLocation(),GetActorRotation(), SpawnParams);
		}
	}
}

void AEternal_Grace_ArenaEnemy_Caster::Tick(float DeltaSeconds)
{

	Super::Tick(DeltaSeconds);

	TestCountdown -= DeltaSeconds;
	if (TestCountdown <= 0)
	{
		TestCountdown = TestTimer;
		CastSpell();
	}
}
