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
			HeavyAttack();
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
			if (StaminaComponent->CurrentStamina <= 0.0f || GetVelocity().Size() < 50.f)
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
		EnhancedInputComponent->BindAction(HeavyAttackAction, ETriggerEvent::Completed, this, &APlayerCharacter::HeavyAttack);

	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void APlayerCharacter::Sprint()
{
	if (StaminaComponent->CurrentStamina >= 0.1f && GetVelocity().Size() > 50.f)
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
		if (!CharacterAnimationInstance->isAttacking && !GetMovementComponent()->IsFalling())
		{
			CharacterAnimationInstance->isAttacking = true;
			//INTERUPT BLOCKING STATE IF BLOCKING
			if (CharacterAnimationInstance->isGuarding)
			{
				CancelGuard(); // THIS IS NOT GOOD: BETWEEN ATTACK THERE IS A SMALL WINDOW WHERE GUARD IS ACTIVATED. NEED TO CHANGE THIS LATER
			}

			TArray<UAnimMontage*> Attacks = WeaponComponent->GetCurrentLightAttacks();
			int AttackIndex = CharacterAnimationInstance->attackCount;
			if (Attacks[AttackIndex] != nullptr)
			{
				PlayAnimMontage(Attacks[AttackIndex], 1.0f);
			}
		}
	}
}

void APlayerCharacter::ChargeHeavyAttack()
{
	if (StaminaComponent->CurrentStamina >= 1.0f&& !GetMovementComponent()->IsFalling())
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

void APlayerCharacter::HeavyAttack()
{
	if (StaminaComponent->CurrentStamina >= 1.0f && !CharacterAnimationInstance->isInHeavyAttack)
	{
		TArray<UAnimMontage*> HeavyAttacks = WeaponComponent->GetCurrentHeavyAttacks();
		//When Heavy Attack Button is released from charge Position the Player Character unleashes his Heavy Attack 
		if (CharacterAnimationInstance->isCharging)
		{
			CharacterAnimationInstance->isCharging = false; //LEAVE CHARGING STATE
			CharacterAnimationInstance->isAttacking = true; //SET PLAYER IN ATTACK STATE, SO THE ANIMATION CAN NOT BE INTERUPTED BY A LIGHT ATTACK COMMAND
			CharacterAnimationInstance->isInHeavyAttack = true; // SET PLAYER IN HEAVY ATTACK STATE, SO ANOTHER HEAVY ATTACK COMMAND TRIGGERS THE SECOND ATTACK ANIM
			UE_LOG(LogTemp, Warning, TEXT("Character Releases Attack"))
				PlayAnimMontage(HeavyAttacks[0], 1.0f);
		}
		//	else if (CharacterAnimationInstance->isInHeavyAttack)
		//	{
		//		//IF PLAYER IS IN HEAVY ATTACK, A SECOND HEAVY ATTACK COMMAND TRIGGERS THE FOLLOW UP ANIMATION
		//		CharacterAnimationInstance->isInHeavyAttack = false;//LEAVE HEAVY ATTACK STATE, SO THE FOLLOW UP ANIMATION ONLY TRIGGERS ONCE
		//		CharacterAnimationInstance->isAttacking = true; //SET IS ATTACKING TO TRUE TO MAKE SURE THE FOLLOW UP ANIMATION IS NOT CANCELED BY LIGHT ATTACK COMMAND
		//		PlayAnimMontage(HeavyAttacks[1], 1.0f);
		//		UE_LOG(LogTemp, Warning, TEXT("Character Already is not Charging"))
		//	}
	}
}


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
