// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "StaminaComponent.h"
#include "CharacterAnimInstance.h"


APlayerCharacter::APlayerCharacter()
{
	StaminaComponent = CreateDefaultSubobject<UStaminaComponent>("StaminaComponent");
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if(StaminaComponent == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("StaminaComponent could not be found"))
			return;
	}

};

void APlayerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(StaminaComponent && CharacterAnimationInstance)
	{
		if (StaminaComponent->CurrentStamina < StaminaComponent->MaxStamina && StaminaComponent->Exhausted == false && CharacterAnimationInstance->isAttacking == false && CharacterAnimationInstance->isRunning == false)
		{
			if(CharacterAnimationInstance->isGuarding == false)
			{
			StaminaComponent->RegenerateStamina(StaminaComponent->StaminaRegenerationRate * DeltaSeconds);
			}
			else
			{
				StaminaComponent->RegenerateStamina(StaminaComponent->ReducedStaminaRegenerationRate * DeltaSeconds);
			}
		}
	}

}