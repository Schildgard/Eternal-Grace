// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusEffectComponent.h"
#include "Components/PostProcessComponent.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "PlayerCharacter.h"

// Sets default values for this component's properties
UStatusEffectComponent::UStatusEffectComponent()
{

	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UStatusEffectComponent::BeginPlay()
{
	Super::BeginPlay();
	OwningCharacter = Cast<AEternal_Grace_ArenaCharacter>(GetOwner());
	Player = Cast<APlayerCharacter>(OwningCharacter);
	
}


// Called every frame
void UStatusEffectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(isPoisoned && Player)
	{
		if(Player->GetPoisonPostProcessEffect()->BlendWeight< 1.0f)
		{
			Player->GetPoisonPostProcessEffect()->BlendWeight += DeltaTime;
		}

	}
	else if (Player)
	{
		if(Player->GetPoisonPostProcessEffect()->BlendWeight > 0.0f)
		{
			Player->GetPoisonPostProcessEffect()->BlendWeight -= DeltaTime;
		}
	}
}

void UStatusEffectComponent::SetIsPoisoned(bool Condition)
{
	isPoisoned = Condition;
	UE_LOG(LogTemp, Warning, TEXT("Poisen was Set or Unset"))
}

