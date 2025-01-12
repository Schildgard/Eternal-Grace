// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "StaminaComponent.h"
#include "CharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "I_Targetable.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InteractableActor.h"
#include "HealthComponent.h"
#include "ShieldComponent.h"



APlayerCharacter::APlayerCharacter()
{
	StaminaComponent = CreateDefaultSubobject<UStaminaComponent>("StaminaComponent");

	RunningStaminaConsumption = 15.0f;
	GuardCounterReactionCountdown = GuardCounterReactionTimer;

	currentChargePower = 0.0f;
	maxChargePower = 2.0f;
}

void APlayerCharacter::ToggleLockOn()
{
	if (CharacterAnimationInstance->isLockedOn == false)
	{
		AActor* ClosestTarget = FindNearestTarget();
		if (ClosestTarget)
		{
			EngageLockOn(ClosestTarget);
			UE_LOG(LogTemp, Warning, TEXT("Lock On"))
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("No Lock on Target in Range"))
		}
	}
	else
	{
		DisengageLockOn();
		UE_LOG(LogTemp, Warning, TEXT("Lock On Off"))
	}
}

void APlayerCharacter::SwitchLockOnTarget()
{
}

AActor* APlayerCharacter::FindNearestTarget()
{
	//GET SCANNED ACTOR ARRAY FROM SCAN FUNCTION
	TArray<AActor*> ScannedActors = ScanForTargets();
	if (ScannedActors.Num() <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Find Nearest Target: No Actors Scanned"))
			return nullptr;
	}


	AActor* ClosestTarget = nullptr;
	float comparison = 0.0f;
	float distance = 10000.0f;

	//ITERATE THROUGH SCANNED ACTORS TO FIND SMALLEST DISTANCE
	for (AActor* Actor : ScannedActors)
	{
		comparison = GetDistanceTo(Actor);
		if (comparison <= distance)
		{
			distance = comparison; //SAVE SMALLEST DISTANCE
			ClosestTarget = Actor; //SAVE ACTOR IF DISTANCE IS SMALLEST
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Nearest Actor: %s "), *ClosestTarget->GetName());
	return ClosestTarget;
}

TArray<AActor*> APlayerCharacter::ScanForTargets()
{
	FVector PlayerPosition = GetActorLocation();
	TArray<FHitResult> ScanHits; //SET UP A LIST FOR HITTED OBJECTS
	TArray<AActor*> ActorsToIgnore; //SET UP A LIST SO ACTORS WONT GET SCANNED MULTIPLE TIMES
	TArray<AActor*> ScannedActors;
	UKismetSystemLibrary::SphereTraceMultiForObjects(world, PlayerPosition, PlayerPosition, 750.0f, ObjectTypes, true, ActorsToIgnore, EDrawDebugTrace::None, ScanHits, true, FLinearColor::Red, FLinearColor::Green, 5.0f);

	if (ScanHits.Num() > 0)
	{
		//ITERARE THROUGH SCANHITS
		for (const FHitResult& Hit : ScanHits)
		{
			AActor* HitActor = Hit.GetActor();
			//ADD HITTED ACTOR TO IGNORE AND VIABLE TARGET LIST
			if (HitActor && HitActor != this && !ActorsToIgnore.Contains(HitActor) && HitActor->Implements<UI_Targetable>())
			{
				ScannedActors.Add(HitActor);
				ActorsToIgnore.Add(HitActor);
			}
		}
	}
	return ScannedActors;
}

void APlayerCharacter::EngageLockOn(AActor* Target)
{
	CharacterAnimationInstance->isLockedOn = true;
	LockedOnTarget = Target;

	if (LockedOnTarget != nullptr)
	{
		FRotator Look = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), LockedOnTarget->GetActorLocation());
		SetActorRotation(Look);
	}
	UE_LOG(LogTemp, Warning, TEXT("No LockedOnTarget"))
}

void APlayerCharacter::DisengageLockOn()
{
	CharacterAnimationInstance->isLockedOn = false;
	LockedOnTarget = nullptr;
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
	//PLAYER ROTATION WHILE LOCK ON
	if (CharacterAnimationInstance && CharacterAnimationInstance->isLockedOn && LockedOnTarget != nullptr && CharacterAnimationInstance->isRunning == false)
	{
		RotateTowardsTarget(LockedOnTarget);
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
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

		//Lock On
		EnhancedInputComponent->BindAction(ToggleLockOnAction, ETriggerEvent::Triggered, this, &APlayerCharacter::ToggleLockOn);
		EnhancedInputComponent->BindAction(SwitchLockOnTargetAction, ETriggerEvent::Triggered, this, &APlayerCharacter::SwitchLockOnTarget);
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
		Super::LightAttack();
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

void APlayerCharacter::HeavyAttack()
{
	if (StaminaComponent->CurrentStamina >= 1.0f)
	{

		//When Heavy Attack Button is released from charge Position the Player Character unleashes his Heavy Attack 
		if (CharacterAnimationInstance->isCharging)
		{
			CharacterAnimationInstance->isCharging = false; //LEAVE CHARGING STATE
			CharacterAnimationInstance->isAttacking = true; //SET PLAYER IN ATTACK STATE, SO THE ANIMATION CAN NOT BE INTERUPTED BY A LIGHT ATTACK COMMAND
			CharacterAnimationInstance->isInHeavyAttack = true; // SET PLAYER IN HEAVY ATTACK STATE, SO ANOTHER HEAVY ATTACK COMMAND TRIGGERS THE SECOND ATTACK ANIM
			UE_LOG(LogTemp, Warning, TEXT("Character Releases Attack"))
				PlayAnimMontage(HeavyAttacks[0], 1.0f);
		}
		else if (CharacterAnimationInstance->isInHeavyAttack)
		{
			//IF PLAYER IS IN HEAVY ATTACK, A SECOND HEAVY ATTACK COMMAND TRIGGERS THE FOLLOW UP ANIMATION
			CharacterAnimationInstance->isInHeavyAttack = false;//LEAVE HEAVY ATTACK STATE, SO THE FOLLOW UP ANIMATION ONLY TRIGGERS ONCE
			CharacterAnimationInstance->isAttacking = true; //SET IS ATTACKING TO TRUE TO MAKE SURE THE FOLLOW UP ANIMATION IS NOT CANCELED BY LIGHT ATTACK COMMAND
			PlayAnimMontage(HeavyAttacks[1], 1.0f);
			UE_LOG(LogTemp, Warning, TEXT("Character Already is not Charging"))
		}


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

//void APlayerCharacter::GetDamage_Implementation(float Damage, float PoiseDamage, float DamageDirection, EStaggeringType StaggerType, AEternal_Grace_ArenaCharacter* DamageSource)
//{
//	Super::GetDamage_Implementation()
//	//if (ShieldComponent && ShieldComponent->GetCurrentShield())
//	//{
//	//	if (CharacterAnimationInstance->isGuarding)
//	//	{
//	//		//Check if Attack is Frontal - NOT SURE IF THIS CALCULATION IS CORRECT
//	//		if (DamageDirection <= 135.0f && DamageDirection >= 180.0f)
//	//		{
//	//			ShieldComponent->BlockDamage(Damage, PoiseDamage, DamageDirection, StaggerType, DamageSource);
//	//			return;
//	//		}
//	//	}
//	//}
//
////	HealthComponent->CurrentHealth -= Damage;
////	UE_LOG(LogTemp, Warning, TEXT("%s got %f Damage"), *GetName(), Damage)
////
////		if (StaggerComponent)
////		{
////			StaggerComponent->GetStaggered(StaggerType, PoiseDamage, DamageDirection, DamageSource);
////		}
////
////
////	if (HealthComponent->CurrentHealth <= 0)
////	{
////		HealthComponent->CurrentHealth = 0;
////		Execute_Die(this);
////	}
//}
