// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "CharacterAnimInstance.h"
#include "CharacterShield.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	MaxHealth = 1000.0f;
	MaxPoise = 25.0f;
	CurrentHealth = MaxHealth;
	CurrentPoise = MaxPoise;
	PoiseRegenerationRate = 0.0f;
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

	if(CurrentPoise<= MaxPoise)
	{
		CurrentPoise += DeltaTime * PoiseRegenerationRate;
	}


}


void UHealthComponent::GetDamage(float IncomingDamage, float PoiseDamage, float DamageDirection, EStaggeringType StaggerType, AEternal_Grace_ArenaCharacter* DamageSource)
{
	AActor* Owner = GetOwner();
	AEternal_Grace_ArenaCharacter* Character = Cast<AEternal_Grace_ArenaCharacter>(Owner);

	CurrentHealth -= IncomingDamage;
	CurrentPoise -= PoiseDamage;


	//ATTACK FROM BEHIND
	if (DamageDirection >= 135.0f && DamageDirection <= 180.0f && CurrentPoise <= 0.0f)
	{
		switch (StaggerType)
		{
		case EStaggeringType::NormalStagger:
			Character->PlayAnimMontage(Character->StaggerAnimsBack[0]);
			CurrentPoise = MaxPoise;
			break;
		case EStaggeringType::HeavyStagger:
			Character->PlayAnimMontage(Character->StaggerAnimsBack[1]);
			CurrentPoise = MaxPoise;
			break;
		case EStaggeringType::KnockbackStagger:
			Character->PlayAnimMontage(Character->StaggerAnimsBack[2]);
			CurrentPoise = MaxPoise;
			break;
		case EStaggeringType::ThrowupStagger:
			Character->PlayAnimMontage(Character->StaggerAnimsBack[3]);
			CurrentPoise = MaxPoise;
			break;
		case EStaggeringType::CrushdownStagger:
			Character->PlayAnimMontage(Character->StaggerAnimsBack[4]);
			CurrentPoise = MaxPoise;
			break;
		case EStaggeringType::NoStagger:
			break;
		}
	}
	else if(CurrentPoise <= 0.0f)//FRONTAL ATTACK WITHOUT GUARD OR SIDE ATTACK
	{
		switch (StaggerType)
		{
		case EStaggeringType::NormalStagger:
			Character->PlayAnimMontage(Character->StaggerAnims[0]);
			CurrentPoise = MaxPoise;
			break;
		case EStaggeringType::HeavyStagger:
			Character->RotateTowardsTarget(DamageSource);
			Character->PlayAnimMontage(Character->StaggerAnims[1]);
			CurrentPoise = MaxPoise;
			break;
		case EStaggeringType::KnockbackStagger:
			if (CurrentHealth <= 0)
			{
				Character->RotateTowardsTarget(DamageSource);
				Character->PlayAnimMontage(Character->DeathAnimationWithKnockBack);
				CurrentPoise = MaxPoise;
				return;
			}
			Character->RotateTowardsTarget(DamageSource);
			Character->PlayAnimMontage(Character->StaggerAnims[2]);
			CurrentPoise = MaxPoise;
			break;
		case EStaggeringType::ThrowupStagger:
			Character->RotateTowardsTarget(DamageSource);
			Character->PlayAnimMontage(Character->StaggerAnims[3]);
			CurrentPoise = MaxPoise;
			break;
		case EStaggeringType::CrushdownStagger:
			Character->RotateTowardsTarget(DamageSource);
			Character->PlayAnimMontage(Character->StaggerAnims[4]);
			CurrentPoise = MaxPoise;
			break;
		case EStaggeringType::NoStagger:
			break;
		}
	}
	if (CurrentHealth <= 0)
	{
		CurrentHealth = 0;
		Die();
	}
}

void UHealthComponent::BlockDamage(float Damage, float PoiseDamage, float DamageDirection, EStaggeringType StaggerType, AEternal_Grace_ArenaCharacter* DamageSource)
{

	AActor* Owner = GetOwner();
	AEternal_Grace_ArenaCharacter* Character = Cast<AEternal_Grace_ArenaCharacter>(Owner);

	Damage -= (Damage / 100) * Character->Shield->PhysicalDamageReduction;
	CurrentHealth -= Damage;
	//STILL HAVE TO THINK ABOUT WETHER AND HOW TO IMPLEMENT POISE HERE
		switch (StaggerType)
		{
		case EStaggeringType::NormalStagger:
			Character->PlayAnimMontage(Character->Block);
			break;
		case EStaggeringType::HeavyStagger:
			Character->PlayAnimMontage(Character->BlockHeavyAttack);
			break;
		case EStaggeringType::KnockbackStagger:
			Character->PlayAnimMontage(Character->BlockThrowbackAttack);
			break;
		case EStaggeringType::ThrowupStagger:
			Character->PlayAnimMontage(Character->BlockThrowbackAttack);
			break;
		case EStaggeringType::CrushdownStagger:
			Character->PlayAnimMontage(Character->BlockThrowbackAttack);
			break;
		default:
			break;
		}
}

void UHealthComponent::Die()
{

	AActor* Owner = GetOwner();
	AEternal_Grace_ArenaCharacter* Character = Cast<AEternal_Grace_ArenaCharacter>(Owner);

	if (Character)
	{
		Character->PlayAnimMontage(Character->DeathAnimation);
		Character->SetActorEnableCollision(false);
	}
	else return;

}