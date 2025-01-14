// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellComponent.h"

// Sets default values for this component's properties
USpellComponent::USpellComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
//	InstigatingActor = nullptr;
	// ...
}


// Called when the game starts
void USpellComponent::BeginPlay()
{
	Super::BeginPlay();
	//InstigatingActor = Cast <AEternal_Grace_ArenaCharacter>(GetOwner());
//	if(!InstigatingActor)
//	{
//		UE_LOG(LogTemp, Error, TEXT("SpellComponent could not be casted into a Eternal Grace Character"))
//	}

	// ...
	
}


// Called every frame
void USpellComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USpellComponent::CastSpell(ASpell* SpellToCast)
{

	UE_LOG(LogTemp, Warning, TEXT("%s was casted through Spell Component"), *SpellToCast->GetName())
}

void USpellComponent::SetTargetPosition(FVector NewPosition)
{
	TargetPosition = NewPosition;
}

FVector USpellComponent::GetTargetPosition()
{
	return TargetPosition;
}

//AEternal_Grace_ArenaCharacter* USpellComponent::GetInstigator()
//{
//	return InstigatingActor;
//}

