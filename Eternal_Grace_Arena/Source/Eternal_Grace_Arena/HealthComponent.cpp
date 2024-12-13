// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "Eternal_Grace_ArenaCharacter.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
//	PrimaryComponentTick.bCanEverTick = true;

	// ...
	MaxHealth = 1000.0f;
	CurrentHealth = MaxHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UHealthComponent::GetDamage(float IncomingDamage)
{
	AActor* Owner = GetOwner();
	AEternal_Grace_ArenaCharacter* Character = Cast<AEternal_Grace_ArenaCharacter>(Owner);

	CurrentHealth -= IncomingDamage;
	if(Character->StaggerAnims[0])
	{
	Character->PlayAnimMontage(Character->StaggerAnims[0]);
	UE_LOG(LogTemp, Warning, TEXT("Hit ANim"))

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("You Failed to stand my ground"))
	}

	if (CurrentHealth <= 0)
	{
		CurrentHealth = 0;
		Die();
	}

}

void UHealthComponent::Die()
{

	AActor* Owner = GetOwner();
	AEternal_Grace_ArenaCharacter* Character = Cast<AEternal_Grace_ArenaCharacter>(Owner);

	if (Character)
	{

	}
	else return;

}