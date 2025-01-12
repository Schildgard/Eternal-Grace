// Fill out your copyright notice in the Description page of Project Settings.


#include "ShieldComponent.h"
#include "Shield.h"
#include "CharacterAnimInstance.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "HealthComponent.h"
#include "StaminaComponent.h"
#include "PlayerCharacter.h"

// Sets default values for this component's properties
UShieldComponent::UShieldComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	EquippedShield = nullptr;
	OwningCharacter = nullptr;
	OwningPlayer = nullptr;
	OwnersAnimationInstance = nullptr;

	// ...
}


// Called when the game starts
void UShieldComponent::BeginPlay()
{
	Super::BeginPlay();

	OwningCharacter = Cast<AEternal_Grace_ArenaCharacter>(GetOwner());
	if (!OwningCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("Shield Component of %s Could not Cast its Owner to an EternalGrace Character"), *GetOwner()->GetName())
			return;
	}

	OwnersAnimationInstance = OwningCharacter->CharacterAnimationInstance;
	if (!OwnersAnimationInstance)
	{
		UE_LOG(LogTemp, Error, TEXT("Shield Component of %s Could not get Animation Instance"), *GetOwner()->GetName())
			return;
	}
	OwningPlayer = Cast<APlayerCharacter>(OwningCharacter);

	// ...

}


// Called every frame
void UShieldComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UShieldComponent::BlockDamage(float Damage, float PoiseDamage, float DamageDirection, EStaggeringType StaggerType, AEternal_Grace_ArenaCharacter* DamageSource)
{
	if (!OwningCharacter)
	{
		UE_LOG(LogTemp, Error, TEXT("Shield Components Owner %s is no Eternal Grace Character. BlockFunction canceled."), *GetOwner()->GetName())
			return;
	}

	//CALCULTE AND DEAL DAMAGE
	Damage -= (Damage / 100) * EquippedShield->GetShieldStats().PhysicalDamageReduction;
	OwningCharacter->HealthComponent->CurrentHealth -= Damage;


	//CALCULTE AND APPLY STAMINA DMG ON PLAYER
	if (OwningPlayer)
	{
		float StaminaDamage = PoiseDamage -((PoiseDamage/100) * EquippedShield->GetShieldStats().Stability);
		OwningPlayer->StaminaComponent->CurrentStamina -= StaminaDamage;
		if (OwningPlayer->StaminaComponent->CurrentStamina <= 0)
		{
			CancelGuard();
			OwningPlayer->PlayAnimMontage(GuardBreakAnimation);
			return;
		}
	}
	//APPLY BLOACK REACTION
	if (BlockAnimationMap.Contains(StaggerType))
	{
		OwningCharacter->PlayAnimMontage(BlockAnimationMap[StaggerType]);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s BlockAnimation Map did not contain an Animation for that StaggerType"), *OwningCharacter->GetName())
	}

}

void UShieldComponent::Guard()
{
	if (!OwnersAnimationInstance->isGuarding)
	{
		OwnersAnimationInstance->isGuarding = true;
	}
}

void UShieldComponent::CancelGuard()
{
	if (OwnersAnimationInstance->isGuarding)
	{
		OwnersAnimationInstance->isGuarding = false;
	}
}

