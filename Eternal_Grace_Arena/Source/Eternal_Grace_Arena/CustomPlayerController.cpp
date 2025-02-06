// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "HealthComponent.h"
#include "StaminaComponent.h"
#include "BlendingWidget.h"
#include "AnimatedWidget.h"
#include "Kismet/GameplayStatics.h"
#include "EternalGrace_GameInstance.h"
#include "LockOnSystem.h"
#include "I_Targetable.h"
#include "CharacterAnimInstance.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"

ACustomPlayerController::ACustomPlayerController()
{
	PlayerCharacter = nullptr;
	HUDWidgetClass = nullptr;
	HUDWidget = nullptr;
	YouDiedScreenClass = nullptr;
	YouDiedWidget = nullptr;
	ActiveGameInstance = nullptr;


	LockOnSystem = CreateDefaultSubobject<ULockOnSystem>(TEXT("LockOnSystem"));
}
void ACustomPlayerController::ShowYouDiedScreen()
{
	if (YouDiedScreenClass)
	{
		//CREATE OBJECT OF YOU DIED SCREEN CLASS
		YouDiedWidget = CreateWidget<UBlendingWidget>(this, YouDiedScreenClass);
		if (YouDiedWidget)
		{
			//ACTIVATE YOU DIED SCREEN TO VIEWPORT
			YouDiedWidget->AddToViewport();
			if (YouDiedWidget->BlendingAnimation)
			{
				//ACTIVATE BLEND IN ANIMATION
				YouDiedWidget->PlayAnimation(YouDiedWidget->BlendingAnimation);
				//BIND LEVEL RELOAD TO YOU DIED SCREEN
				FWidgetAnimationDynamicEvent Reload;
				Reload.BindDynamic(this, &ACustomPlayerController::ReloadLevel);
				YouDiedWidget->BindToAnimationFinished(YouDiedWidget->BlendOutAnimation, Reload);
				//MAKE BLEND OUT ASYNCHRON OR SOMETHING????
			}
			//DEACTIVATE INPUT
			FInputModeUIOnly InputMode;
			SetInputMode(InputMode);
		}
	}
}


void ACustomPlayerController::HideYouDiedScreen()
{
	if (YouDiedWidget)
	{
		YouDiedWidget->RemoveFromViewport();
		//REACTIVATE INPUT
		FInputModeGameOnly InputMode;
		SetInputMode(InputMode);
	}

}
void ACustomPlayerController::HandlePlayerDeath()
{
	ShowYouDiedScreen();
}

void ACustomPlayerController::ShowBossHPBar()
{
	if (BossHPBarClass)
	{
		BossHPBar = CreateWidget<UPlayer_UI_Bars>(this, BossHPBarClass);
		if (BossHPBar)
		{
			BossHPBar->AddToViewport();
			UWidgetAnimation* BlendInAnimation = BossHPBar->GetBlendInAnimation();
			if (BlendInAnimation)
			{
				BossHPBar->PlayAnimation(BlendInAnimation);
			}
		}
	}
}

void ACustomPlayerController::HideBossHPBar()
{
	if (BossHPBar)
	{
		UWidgetAnimation* BlendOutAnimation = BossHPBar->GetBlendOutAnimation();
		if (BlendOutAnimation)
		{
			BossHPBar->PlayAnimation(BlendOutAnimation);
		}
		else
		{
			BossHPBar->RemoveFromViewport();
		}
	}

}

UPlayer_UI_Bars* ACustomPlayerController::GetBossHPBarWidget()
{
	return BossHPBar;
}



void ACustomPlayerController::ToggleLockOn()
{
	if (LockOnSystem->GetLockedOnTarget())
	{
		LockOnSystem->UnlockTarget();
		PlayerCharacter->CharacterAnimationInstance->isLockedOn = false;
	}
	else
	{
		AEternal_Grace_ArenaCharacter* Target = FindNearestTarget();
		if (Target)
		{
			LockOnSystem->LockOnTarget(FindNearestTarget(), PlayerCharacter);
			PlayerCharacter->CharacterAnimationInstance->isLockedOn = true;
		}
	}
}


AEternal_Grace_ArenaCharacter* ACustomPlayerController::FindNearestTarget()
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
		comparison = PlayerCharacter->GetDistanceTo(Actor);
		if (comparison <= distance)
		{
			distance = comparison; //SAVE SMALLEST DISTANCE
			ClosestTarget = Actor; //SAVE ACTOR IF DISTANCE IS SMALLEST
		}
	}

	AEternal_Grace_ArenaCharacter* NewTarget = Cast<AEternal_Grace_ArenaCharacter>(ClosestTarget);
	return NewTarget;
}

TArray<AActor*> ACustomPlayerController::ScanForTargets()
{
	FVector PlayerPosition = PlayerCharacter->GetActorLocation();
	TArray<FHitResult> ScanHits; //SET UP A LIST FOR HITTED OBJECTS
	TArray<AActor*> ActorsToIgnore; //SET UP A LIST SO ACTORS WONT GET SCANNED MULTIPLE TIMES
	TArray<AActor*> ScannedActors;
	UKismetSystemLibrary::SphereTraceMultiForObjects(GetWorld(), PlayerPosition, PlayerPosition, 750.0f, ObjectTypes, true, ActorsToIgnore, EDrawDebugTrace::None, ScanHits, true, FLinearColor::Red, FLinearColor::Green, 5.0f);

	if (ScanHits.Num() > 0)
	{
		//ITERARE THROUGH SCANHITS
		for (const FHitResult& Hit : ScanHits)
		{
			AActor* HitActor = Hit.GetActor();
			//ADD HITTED ACTOR TO IGNORE AND VIABLE TARGET LIST
			if (HitActor && HitActor != PlayerCharacter && !ActorsToIgnore.Contains(HitActor) && HitActor->Implements<UI_Targetable>())
			{
				ScannedActors.Add(HitActor);
				ActorsToIgnore.Add(HitActor);
			}
		}
	}
	return ScannedActors;
}




void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(ToggleLockOnAction, ETriggerEvent::Triggered, this, &ACustomPlayerController::ToggleLockOn);
	}
}
void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//CREATE AND SHOW PLAYER HUD
	if (HUDWidgetClass != nullptr)
	{
		HUDWidget = CreateWidget<UPlayer_UI_Bars>(this, HUDWidgetClass);
		HUDWidget->AddToViewport();
	}
	PlayerCharacter = Cast<APlayerCharacter>(AcknowledgedPawn);
	if (PlayerCharacter)
	{
		//SUBSCRIBE DEATH HANDLING TO ON DIE EVENT
		PlayerCharacter->OnCharacterDeath.AddDynamic(this, &ACustomPlayerController::HandlePlayerDeath);
		//SUBSCRIBE RESET HEALTH INFORMATION TO DIE EVENT 
		ActiveGameInstance = Cast<UEternalGrace_GameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
		if (ActiveGameInstance)
		{
			PlayerCharacter->OnCharacterDeath.AddDynamic(ActiveGameInstance, &UEternalGrace_GameInstance::ResetHealthInformation);
		}
	}
};

void ACustomPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (HUDWidget)
	{
		HUDWidget->UpdateProgressBar(HUDWidget->Healthbar, PlayerCharacter->HealthComponent->MaxHealth, PlayerCharacter->HealthComponent->CurrentHealth);
		HUDWidget->UpdateProgressBar(HUDWidget->Staminabar, PlayerCharacter->StaminaComponent->MaxStamina, PlayerCharacter->StaminaComponent->CurrentStamina);
	}

	if (LockOnSystem && LockOnSystem->GetLockedOnTarget())
	{
		LockOnSystem->UpdateLockOn(PlayerCharacter, DeltaSeconds);
	}
}

void ACustomPlayerController::ReloadLevel()
{
	ActiveGameInstance->ReturnToMainLevel();

	//REACTIVATE INPUT
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}
