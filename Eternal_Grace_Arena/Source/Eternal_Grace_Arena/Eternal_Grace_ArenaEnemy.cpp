// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ArenaEnemy.h"
#include "CharacterAnimInstance.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet//GameplayStatics.h"
#include "Perception/PawnSensingComponent.h"
#include "EternalGrace_GameInstance.h"
#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
AEternal_Grace_ArenaEnemy::AEternal_Grace_ArenaEnemy()
{
	HPBarComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HP Bar"));
	HPBarComponent->SetupAttachment(RootComponent);
	HPBarComponent->SetWidgetSpace(EWidgetSpace::Screen);
	HPBarComponent->SetRelativeLocation(FVector(0, 0, 163.0f));
	AttackRange = 350.f;
	HealthbarWidget = nullptr;

	ChasingDistanceThreshold = 300.0f;
	ChasingCountDown = ChasingTimer;
	ReturningToStartPosition = false;

	BackDetection = -0.35f;
	CanPerformGettOffMeMove = false;
	SensingComponent = CreateDefaultSubobject<UPawnSensingComponent>("Pawn Sensing");
}

bool AEternal_Grace_ArenaEnemy::CheckDistancetoPlayer(float Threshold)
{
	FVector OwnerLocation = GetActorLocation();
	FVector PlayerLocation = UGameplayStatics::GetPlayerCharacter(world, 0)->GetActorLocation();
	float Distance = UKismetMathLibrary::Vector_Distance(PlayerLocation, OwnerLocation);
	if (Distance >= Threshold)
	{
		return false;
	}
	else return true;
}

void AEternal_Grace_ArenaEnemy::GetOffMeMove()
{
	if (!CharacterAnimationInstance->isAttacking)
	{
		CharacterAnimationInstance->isAttacking = true;

		//TEMPORARY
		UCapsuleComponent* ActorCollisionCapsule = GetCapsuleComponent();
		ActorCollisionCapsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);


			RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(world, 0));
		if (CharacterAnimationInstance->isGuarding)
		{
			CancelGuard();
		}
		if (AttackMontages[2] != nullptr)
		{
			PlayAnimMontage(AttackMontages[2], 1.0f); // TO DO:REPLACE THAT MAGIC NUMBER WITH SOMETHING ELSE LIKE A POINTER TO A SPECIFIC MONTAGE OR SOMETHING
			FOnMontageEnded InterruptDelegate;
			InterruptDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::InterruptAttack);
			CharacterAnimationInstance->Montage_SetBlendingOutDelegate(InterruptDelegate, AttackMontages[2]);
			CharacterAnimationInstance->Montage_SetEndDelegate(InterruptDelegate, AttackMontages[2]);
		}
	}
}

void AEternal_Grace_ArenaEnemy::BeginPlay()
{
	Super::BeginPlay();
	if (HPBarComponent)
	{
		UUserWidget* Widget = HPBarComponent->GetWidget();
		if (Widget)
		{
			HealthbarWidget = Cast<UEnemy_UI_Healthbar>(Widget);
			if (HealthbarWidget == nullptr)
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed Widget to CustomProgressbar"))
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("HBBar has no widget"))
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("HP Bar is null"))
	}

	if (SensingComponent)
	{
		SensingComponent->OnSeePawn.AddDynamic(this, &AEternal_Grace_ArenaEnemy::SpotPlayer);
	}

}

void AEternal_Grace_ArenaEnemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (HealthbarWidget)
	{
		if (HealthComponent)
		{
			HealthbarWidget->UpdateProgressBar(HealthbarWidget->Healthbar, HealthComponent->MaxHealth, HealthComponent->CurrentHealth);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Health Component is null"))
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Healthbar widget is null"))
	}

	if(this->HealthComponent->CurrentHealth <= this->HealthComponent->MaxHealth/2 && !CanPerformGettOffMeMove)
	{
		//CanPerformGettOffMeMove = true;
		TriggerSecondPhase();
		
	}
	



	//if(isAggro)
	//{
	//	if(CheckDistancetoPlayer(ChasingDistanceThreshold) == false)
	//	{
	//		ChasingCountDown -= DeltaSeconds;
	//		if(ChasingCountDown <= 0.0f)
	//		{
	//			ChasingCountDown = ChasingTimer;
	//			isAggro = false;
	//			ReturningToStartPosition = true;
	//			//INSERT RETURN TO START POSITION
	//		}
	//	}
	//	else
	//	{
	//		ChasingCountDown = ChasingTimer;
	//	}
	//}
}

void AEternal_Grace_ArenaEnemy::DeathEvent()
{
	Super::DeathEvent();
	SendInfoToGameInstance();
}

void AEternal_Grace_ArenaEnemy::LightAttack()
{

	if(ShowDistanceVectorToPlayer() < BackDetection && CanPerformGettOffMeMove)
	{
		GetOffMeMove();
		return;
	}




	if (!CharacterAnimationInstance->isAttacking)
	{
		CharacterAnimationInstance->isAttacking = true;
		RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(world, 0));
		if (CharacterAnimationInstance->isGuarding)
		{
			CancelGuard();
		}
		int RandomAttackIndex = UKismetMathLibrary::RandomInteger(2);

		PlayAnimMontage(AttackMontages[RandomAttackIndex], 1.0f);

		FOnMontageEnded InterruptDelegate;
		InterruptDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::InterruptAttack);
		CharacterAnimationInstance->Montage_SetBlendingOutDelegate(InterruptDelegate, AttackMontages[RandomAttackIndex]);
		CharacterAnimationInstance->Montage_SetEndDelegate(InterruptDelegate, AttackMontages[RandomAttackIndex]);
		//
		//		FOnMontageEnded CompletedDelegate;
		//		CompletedDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::OnAttackEnd);
		//		CharacterAnimationInstance->Montage_SetEndDelegate(CompletedDelegate, LightAttacks[0]);
		//		UE_LOG(LogTemp, Warning, TEXT("is AGAIN TEST Attacking : %s"), CharacterAnimationInstance->isAttacking ? TEXT("true") : TEXT("false"));
			//UE_LOG(LogTemp, Warning, TEXT("is Attacking : %s"), CharacterAnimationInstance->isAttacking ? TEXT("true") : TEXT("false"));
	}
}

void AEternal_Grace_ArenaEnemy::SpotPlayer(APawn* SpottedPawn)
{
	if (!isAggro && !ReturningToStartPosition)
	{
		isAggro = true;
		UE_LOG(LogTemp, Warning, TEXT("Enemy Spotted Player"))
			//CHECK IF THERE COULD BE A PROBLEM WITH RACE CONDITION IN LINE 118, SINCE THE EVENT CALL ALSO SETS ISAGGRO
	}
}

void AEternal_Grace_ArenaEnemy::SendInfoToGameInstance()
{
	UE_LOG(LogTemp, Warning, TEXT("Trigger"))
		//IT ACTUALLY MAKES SENSE TO MOVE THIS TO A BOSS CLASS, SINCE REGULAR ENEMIES DONT AFFECT ANYTHING IN THE WORLD
		UEternalGrace_GameInstance* CurrentInstance = Cast<UEternalGrace_GameInstance>(UGameplayStatics::GetGameInstance(world));
	if (CurrentInstance)
	{
		for (const TPair<FName, bool>& Pair : ReferencedObjectIds)
		{
			CurrentInstance->SetObjectState(Pair.Key, Pair.Value);
			UE_LOG(LogTemp, Warning, TEXT("Iterated through %s"), *Pair.Key.ToString())

		}
	}
}

float AEternal_Grace_ArenaEnemy::ShowDistanceVectorToPlayer()
{
	FColor DebugColor = FColor::Black;
	FVector OwnerLocation = GetActorLocation();
	FVector OwnerForwardDirection = GetActorForwardVector();
	//FVector EndPoint = OwnerLocation + (OwnerForwardDirection * 1000.0f);
	FVector PlayerLocation = UGameplayStatics::GetPlayerCharacter(world, 0)->GetActorLocation();

	FVector OwnerPlayerDistance = PlayerLocation - OwnerLocation;
	OwnerPlayerDistance.Normalize();

	float dotproduct = UKismetMathLibrary::Dot_VectorVector(OwnerPlayerDistance, OwnerForwardDirection);
	float distance = UKismetMathLibrary::Vector_Distance(OwnerLocation, PlayerLocation);
	if (dotproduct < BackDetection)
	{
		DebugColor = FColor::Green;
	}


	//DrawDebugLine(world, OwnerLocation, EndPoint, FColor::Blue, false);
	DrawDebugLine(world, OwnerLocation, PlayerLocation, DebugColor, false);
	//UE_LOG(LogTemp, Display, TEXT("%f"), distance);

	return dotproduct;
}

void AEternal_Grace_ArenaEnemy::TriggerSecondPhase()
{
	PlayAnimMontage(SecondPhaseMontage, 1.0f);
	CanPerformGettOffMeMove = true;
	UE_LOG(LogTemp, Error, TEXT("Can now perform GetOffMeMove"))
}
