// Fill out your copyright notice in the Description page of Project Settings.


#include "Spells_EffectArea.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Components/PostProcessComponent.h"
#include "CustomPlayerController.h"
#include "StatusEffectComponent.h"

ASpells_EffectArea::ASpells_EffectArea()
{

}

void ASpells_EffectArea::BeginPlay()
{
	Super::BeginPlay();
	HitBox->OnComponentBeginOverlap.AddDynamic(this, &ASpells_EffectArea::ApplyEffect);
	HitBox->OnComponentEndOverlap.AddDynamic(this, &ASpells_EffectArea::RemoveEffect);
}

void ASpells_EffectArea::Tick(float DeltaSeconds)
{


}

void ASpells_EffectArea::SpellEffect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void ASpells_EffectArea::RemoveFromEffectList(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{

}

void ASpells_EffectArea::ApplyEffect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AEternal_Grace_ArenaCharacter* EnteringCharacter = Cast<AEternal_Grace_ArenaCharacter>(OtherActor);
	if (EnteringCharacter)
	{
		UStatusEffectComponent* StatusComponent = EnteringCharacter->GetStatusEffectComponent();
		if (StatusComponent)
		{
			StatusComponent->SetIsPoisoned(true);
			UE_LOG(LogTemp, Warning, TEXT("AccessStatusComponent to remove"))
		}
	}


}

void ASpells_EffectArea::RemoveEffect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	AEternal_Grace_ArenaCharacter* EnteringCharacter = Cast<AEternal_Grace_ArenaCharacter>(OtherActor);
	if (EnteringCharacter)
	{
		UStatusEffectComponent* StatusComponent = EnteringCharacter->GetStatusEffectComponent();
		if (StatusComponent)
		{
			StatusComponent->SetIsPoisoned(false);
			UE_LOG(LogTemp, Warning, TEXT("AccessStatusComponent to remove"))
		}
	}
}
