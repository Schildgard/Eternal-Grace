// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ArenaEnemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet//GameplayStatics.h"
#include "Perception/PawnSensingComponent.h"
#include "EternalGrace_GameInstance.h"
#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
#include "HealthComponent.h"
AEternal_Grace_ArenaEnemy::AEternal_Grace_ArenaEnemy()
{
	HPBarComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HP Bar"));
	HPBarComponent->SetupAttachment(RootComponent);
	HPBarComponent->SetWidgetSpace(EWidgetSpace::Screen);
	HPBarComponent->SetRelativeLocation(FVector(0, 0, 163.0f));
	AttackRange = 350.f;
	HealthbarWidget = nullptr;

	//ChasingDistanceThreshold = 300.0f;
	//ChasingCountDown = ChasingTimer;
	//ReturningToStartPosition = false;

	BackDetection = -0.35f;
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
				UE_LOG(LogTemp, Error, TEXT("%s Failed to cast WidgetProperty to Enemy_UI_Bar"), *GetName())
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Get Widget Function of %s HPBarComponent failed"), *GetName())
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("HP-Bar Component for %s is nullptr"), *GetName())
	}

	if (SensingComponent)
	{
		SensingComponent->OnSeePawn.AddDynamic(this, &AEternal_Grace_ArenaEnemy::SpotPlayer);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Sensing Component of %s could not be getted"), *GetName())
	}

}

void AEternal_Grace_ArenaEnemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (HealthbarWidget)
	{
		if (HealthComponent)
		{
			//UPDATE HP-BAR
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



	// TO DO REFACTOR THIS TO AN EVENT MAYBE?
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

void AEternal_Grace_ArenaEnemy::Die_Implementation()
{
	Super::Die_Implementation();
	SendInfoToGameInstance();
}

void AEternal_Grace_ArenaEnemy::SpotPlayer(APawn* SpottedPawn)
{
	if (!isAggro)
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

bool AEternal_Grace_ArenaEnemy::CheckIfPlayerIsBehind()
{
	FColor DebugColor = FColor::Red;

	FVector OwnerLocation = GetActorLocation();
	FVector OwnerForwardDirection = GetActorForwardVector();
	FVector PlayerLocation = UGameplayStatics::GetPlayerCharacter(world, 0)->GetActorLocation();

	FVector OwnerPlayerDistance = PlayerLocation - OwnerLocation;
	OwnerPlayerDistance.Normalize();

	float dotproduct = UKismetMathLibrary::Dot_VectorVector(OwnerPlayerDistance, OwnerForwardDirection);

	DrawDebugLine(world, OwnerLocation, PlayerLocation, DebugColor, true, 2.0f);
	if (dotproduct < BackDetection)
	{
		DebugColor = FColor::Green;
		return true;
	}

	return false;;
}

void AEternal_Grace_ArenaEnemy::ResetCollision(UAnimMontage* AttackAnimation, bool Interrupted)
{
	if (Interrupted)
	{
		UCapsuleComponent* ActorCollisionCapsule = GetCapsuleComponent();
		ActorCollisionCapsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
	}
}
