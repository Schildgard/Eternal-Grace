// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "StaminaComponent.h"
#include "CharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InteractableActor.h"
#include "HealthComponent.h"
#include "ShieldComponent.h"
#include "WeaponComponent.h"



APlayerCharacter::APlayerCharacter()
{
	StaminaComponent = CreateDefaultSubobject<UStaminaComponent>("StaminaComponent");

	RunningStaminaConsumption = 15.0f;
	GuardCounterReactionCountdown = GuardCounterReactionTimer;

	currentChargePower = 0.0f;
	maxChargePower = 2.0f;
}


void APlayerCharacter::GuardCounterAttack()
{
	if (GuardCounterPossible && !CharacterAnimationInstance->isAttacking && !CharacterAnimationInstance->isCharging && StaminaComponent->CurrentStamina >= 1.0f && GuardCounter != nullptr && CharacterAnimationInstance->isGuarding)
	{
		CharacterAnimationInstance->isAttacking = true;
		CharacterAnimationInstance->isGuarding = false;
		PlayAnimMontage(GuardCounter, 1.0f);
	}
}

void APlayerCharacter::Interact()
{
	TSet<AActor*> OverlappingActors;
	TSubclassOf<AInteractableActor> ViableActorClass;
	GetOverlappingActors(OverlappingActors, ViableActorClass);
	//Cant Access Elements of TSets, thats why it is neccessary to iterate through it, even just to get one item
	if (OverlappingActors.Num() >= 1)
	{
		for (AActor* Overlap : OverlappingActors)
		{

			AInteractableActor* Interactable = Cast<AInteractableActor>(Overlap);
			if (Interactable)
			{
				Interactable->Interact_Implementation();
				break;
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Nothing to Interact"))
	}
}

void APlayerCharacter::IncreaseChargePower()
{

	//When further Hold down, the Player remains in Charge Position and charges Attack power
	if (CharacterAnimationInstance->isCharging)
	{
		currentChargePower += world->DeltaTimeSeconds;
		if (currentChargePower >= maxChargePower)
		{
			currentChargePower = maxChargePower;
			WeaponComponent->HeavyAttack();
		}
	}
}

void APlayerCharacter::SprintAttack()
{
	PlayAnimMontage(RunningAttack);
}

void APlayerCharacter::Dodge()
{
	if (StaminaComponent->CurrentStamina >= 1.0f)
	{
		PlayAnimMontage(DodgeAction);
	}
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

		if (CharacterAnimationInstance->isRunning)
		{
			StaminaComponent->CurrentStamina -= (RunningStaminaConsumption * DeltaSeconds);
			if (StaminaComponent->CurrentStamina <= 0.0f)
			{
				CancelSprint();
			}
		}
	}

	//RESET GUARDCOUNTER REACTIONTIME
	if (GuardCounterPossible)
	{
		GuardCounterReactionCountdown -= DeltaSeconds;
		if (GuardCounterReactionCountdown <= 0)
		{
			GuardCounterReactionCountdown = GuardCounterReactionTimer;
			GuardCounterPossible = false;
		}
	}

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//GuardCounter
		EnhancedInputComponent->BindAction(GuardCounterAction, ETriggerEvent::Completed, this, &APlayerCharacter::GuardCounterAttack);
		//Interactions
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Completed, this, &APlayerCharacter::Interact);

		//Sprinting
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Triggered, this, &APlayerCharacter::Sprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &APlayerCharacter::CancelSprint);
		EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Canceled, this, &APlayerCharacter::CancelSprint);

		//Heavy Attack
		EnhancedInputComponent->BindAction(HeavyAttackAction, ETriggerEvent::Started, this, &APlayerCharacter::ChargeHeavyAttack);
		EnhancedInputComponent->BindAction(HeavyAttackAction, ETriggerEvent::Triggered, this, &APlayerCharacter::IncreaseChargePower);
		EnhancedInputComponent->BindAction(HeavyAttackAction, ETriggerEvent::Completed, WeaponComponent, &UWeaponComponent::HeavyAttack);

	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void APlayerCharacter::Sprint()
{
	if (StaminaComponent->CurrentStamina >= 0.1f)
	{
		CharacterAnimationInstance->isRunning = true;
		GetCharacterMovement()->MaxWalkSpeed = 750.f;
	}
	else if (CharacterAnimationInstance->isRunning)
	{
		CancelSprint();
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
		//Super::LightAttack();
		WeaponComponent->Attack();
	}
}

void APlayerCharacter::ChargeHeavyAttack()
{
	if (StaminaComponent->CurrentStamina >= 1.0f)
	{
		//When Heavy Attack Button is first pressed, Player goes into Charge Stand
		if (!CharacterAnimationInstance->isCharging && !CharacterAnimationInstance->isAttacking && !CharacterAnimationInstance->isInHeavyAttack)
		{
			CharacterAnimationInstance->isCharging = true;
			PlayAnimMontage(ChargeAttack, 1.0f);
			UE_LOG(LogTemp, Warning, TEXT("Character Charges Attack"))
		}
	}
}

//void APlayerCharacter::HeavyAttack()
//{
//	if (StaminaComponent->CurrentStamina >= 1.0f)
//	{
//		WeaponComponent->HeavyAttack();
//	}
//}

void APlayerCharacter::Guard()
{
	if (StaminaComponent->Exhausted == false)
	{
		Super::Guard();
	}
	else
	{
		CancelGuard();
	}
}
