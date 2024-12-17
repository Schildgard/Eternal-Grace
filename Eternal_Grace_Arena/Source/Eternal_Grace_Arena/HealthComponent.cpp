// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "CharacterAnimInstance.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
//	PrimaryComponentTick.bCanEverTick = true;

	// ...
	MaxHealth = 1000.0f;
	MaxPoise = 25.0f;
	CurrentHealth = MaxHealth;
	CurrentPoise = MaxPoise;
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


void UHealthComponent::GetDamage(float IncomingDamage, float PoiseDamage, EStaggeringType StaggerType)
{
	AActor* Owner = GetOwner();
	AEternal_Grace_ArenaCharacter* Character = Cast<AEternal_Grace_ArenaCharacter>(Owner);

	CurrentHealth -= IncomingDamage;
	CurrentPoise -= PoiseDamage;
	if (Character->CharacterAnimationInstance->isGuarding)
	{
		switch (StaggerType)
		{
		case EStaggeringType::NormalStagger:
			Character->PlayAnimMontage(Character->Block);
			break;
		case EStaggeringType::HeavyStagger:
			Character->PlayAnimMontage(Character->BlockHeavyAttack);
			break;
		case EStaggeringType::KnockbackStagger:
			Character->PlayAnimMontage(Character->BlockHeavyAttack);
			break;
		case EStaggeringType::ThrowupStagger:
			Character->PlayAnimMontage(Character->BlockHeavyAttack);
			break;
		case EStaggeringType::CrushdownStagger:
			Character->PlayAnimMontage(Character->BlockHeavyAttack);
			break;
		case EStaggeringType::NoStagger:
			break;
		}
	}
	else if (Character->StaggerAnims[0])
	{
		CurrentPoise = MaxPoise;
		switch (StaggerType)
		{
		case EStaggeringType::NormalStagger:
			Character->PlayAnimMontage(Character->StaggerAnims[0]);
			break;
		case EStaggeringType::HeavyStagger:
			Character->PlayAnimMontage(Character->StaggerAnims[1]);
			break;
		case EStaggeringType::KnockbackStagger:
			Character->PlayAnimMontage(Character->StaggerAnims[2]);
			break;
		case EStaggeringType::ThrowupStagger:
			Character->PlayAnimMontage(Character->StaggerAnims[3]);
			break;
		case EStaggeringType::CrushdownStagger:
			Character->PlayAnimMontage(Character->StaggerAnims[4]);
			break;
		case EStaggeringType::NoStagger:
			Character->PlayAnimMontage(Character->StaggerAnims[0]); //REMOVE THIS
			break;
		}
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