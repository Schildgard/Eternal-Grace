// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusEffectComponent.h"
#include "Components/PostProcessComponent.h"
#include "Eternal_Grace_ArenaCharacter.h"

// Sets default values for this component's properties
UStatusEffectComponent::UStatusEffectComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	isPoisoned = false;
	PoisonDamage = 50.0f;
}


// Called when the game starts
void UStatusEffectComponent::BeginPlay()
{
	Super::BeginPlay();
	OwningCharacter = Cast<AEternal_Grace_ArenaCharacter>(GetOwner());

}


// Called every frame
void UStatusEffectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (isPoisoned)
	{
		II_Damageable::Execute_GetDamage(OwningCharacter, (PoisonDamage * DeltaTime), 0, 0, EStaggeringType::NoStagger, nullptr, false);
	}
}

void UStatusEffectComponent::SetIsPoisoned(bool Condition)
{
	isPoisoned = Condition;
}

bool UStatusEffectComponent::GetIsPoisoned()
{
	return isPoisoned;
}

