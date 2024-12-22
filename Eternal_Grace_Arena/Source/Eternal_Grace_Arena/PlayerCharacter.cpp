// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "StaminaComponent.h"
#include "CharacterAnimInstance.h"
#include "CharacterWeapon.h"
#include "GameFramework/CharacterMovementComponent.h"


APlayerCharacter::APlayerCharacter()
{
	StaminaComponent = CreateDefaultSubobject<UStaminaComponent>("StaminaComponent");
	RunningStaminaConsumption = 15.0f;
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (StaminaComponent == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("StaminaComponent could not be found"))
			return;
	}

};

void APlayerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (StaminaComponent && CharacterAnimationInstance)
	{
		//STAMINA REGENERATION CONDITIONS -> Maybe refactor this to stamina component ?
		if (StaminaComponent->CurrentStamina < StaminaComponent->MaxStamina && StaminaComponent->Exhausted == false
			&& CharacterAnimationInstance->isAttacking == false && CharacterAnimationInstance->isRunning == false &&
			CharacterAnimationInstance->isCharging == false)
		{
			if (CharacterAnimationInstance->isGuarding == false)
			{
				StaminaComponent->RegenerateStamina(StaminaComponent->StaminaRegenerationRate * DeltaSeconds);
			}
			else
			{
				StaminaComponent->RegenerateStamina(StaminaComponent->ReducedStaminaRegenerationRate * DeltaSeconds);
			}
		}

		if(CharacterAnimationInstance->isRunning)
		{
			StaminaComponent->CurrentStamina -= (RunningStaminaConsumption * DeltaSeconds);
			if(StaminaComponent->CurrentStamina <= 0.0f)
			{
				CancelSprint();
			}
		}
	}

}

void APlayerCharacter::Sprint()
{
	if(StaminaComponent->CurrentStamina >= 0.1f)
	{
		CharacterAnimationInstance->isRunning = true;
		GetCharacterMovement()->MaxWalkSpeed = 750.f;
	}
}

void APlayerCharacter::CancelSprint()
{
	CharacterAnimationInstance->isRunning = false;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
}

void APlayerCharacter::LightAttack()
{
	if (StaminaComponent->CurrentStamina >= 1.0f)
	{
		Super::LightAttack();
	}
}

void APlayerCharacter::ChargeHeavyAttack()
{
	if (StaminaComponent->CurrentStamina >= 1.0f)
	{
		Super::ChargeHeavyAttack();
	}
}

void APlayerCharacter::HeavyAttack()
{
	if (StaminaComponent->CurrentStamina >= 1.0f)
	{
		Super::HeavyAttack();
	}
}
