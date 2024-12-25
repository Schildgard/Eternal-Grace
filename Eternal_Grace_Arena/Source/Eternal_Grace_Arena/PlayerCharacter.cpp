// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "StaminaComponent.h"
#include "CharacterAnimInstance.h"
#include "CharacterWeapon.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "I_Targetable.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"


APlayerCharacter::APlayerCharacter()
{
	StaminaComponent = CreateDefaultSubobject<UStaminaComponent>("StaminaComponent");
	RunningStaminaConsumption = 15.0f;
}

void APlayerCharacter::ToggleLockOn()
{
	if (CharacterAnimationInstance->isLockedOn == false)
	{
		AActor* ClosestTarget = FindNearestTarget();
		EngageLockOn(ClosestTarget);
		UE_LOG(LogTemp, Warning, TEXT("Lock On"))
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
	if (CharacterAnimationInstance && CharacterAnimationInstance->isLockedOn && LockedOnTarget != nullptr)
	{
		RotateTowardsTarget(LockedOnTarget);
	}

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {

		//Lock On
		EnhancedInputComponent->BindAction(ToggleLockOnAction, ETriggerEvent::Triggered, this, &APlayerCharacter::ToggleLockOn);
		EnhancedInputComponent->BindAction(SwitchLockOnTargetAction, ETriggerEvent::Triggered, this, &APlayerCharacter::SwitchLockOnTarget);

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
