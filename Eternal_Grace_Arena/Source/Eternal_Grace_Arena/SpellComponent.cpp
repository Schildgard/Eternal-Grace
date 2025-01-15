// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellComponent.h"
#include "Eternal_Grace_ArenaEnemy.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
USpellComponent::USpellComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	TargetCharacter = nullptr;
	TargetPosition = FVector(0.0f);
}


// Called when the game starts
void USpellComponent::BeginPlay()
{
	Super::BeginPlay();
	AEternal_Grace_ArenaEnemy* CasterEnemy = Cast<AEternal_Grace_ArenaEnemy>(GetOwner());
	if(CasterEnemy)
	{
		AEternal_Grace_ArenaCharacter* Player;
		Player = Cast<AEternal_Grace_ArenaCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
		if(Player)
		{
			TargetCharacter = Player;
		}
	}
	
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

AEternal_Grace_ArenaCharacter* USpellComponent::GetTarget()
{
	return TargetCharacter;
}

