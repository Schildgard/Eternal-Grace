// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ArenaEnemy_Caster.h"
#include "SpellComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnPoint.h"

AEternal_Grace_ArenaEnemy_Caster::AEternal_Grace_ArenaEnemy_Caster()
{
	SpellComponent = CreateDefaultSubobject<USpellComponent>("Spells");
}


USpellComponent* AEternal_Grace_ArenaEnemy_Caster::GetSpellComponent()
{
	return SpellComponent;
}

void AEternal_Grace_ArenaEnemy_Caster::BeginPlay()
{
	Super::BeginPlay();
}

void AEternal_Grace_ArenaEnemy_Caster::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
