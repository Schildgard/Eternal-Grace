// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ArenaEnemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet//GameplayStatics.h"
#include "Perception/PawnSensingComponent.h"
#include "EternalGrace_GameInstance.h"
#include "DrawDebugHelpers.h"
#include "Components/CapsuleComponent.h"
#include "HealthComponent.h"
#include "CharacterAnimInstance.h"
#include "WeaponComponent.h"
#include "CustomPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "LockOnSystem.h"

AEternal_Grace_ArenaEnemy::AEternal_Grace_ArenaEnemy()
{

	AttackRange = 350.f;
	HealthbarWidget = nullptr;
	isAggro = false;
	//	HealthbarWidgetClass = nullptr;

		//ChasingDistanceThreshold = 300.0f;
		//ChasingCountDown = ChasingTimer;
		//ReturningToStartPosition = false;

	BackDetection = -0.35f;
	SensingComponent = CreateDefaultSubobject<UPawnSensingComponent>("Pawn Sensing");
}

bool AEternal_Grace_ArenaEnemy::CheckDistancetoPlayer(float Threshold)
{

	FColor DebugColor = FColor::Black;

	//CHECK IF IN RANGE
	FVector OwnerLocation = GetActorLocation();
	FVector PlayerLocation = UGameplayStatics::GetPlayerCharacter(world, 0)->GetActorLocation();
	float Distance = UKismetMathLibrary::Vector_Distance(PlayerLocation, OwnerLocation);

	//if(Distance <= 300.f)
	//{
	//	DebugColor = FColor::Red;
	//
	//}
	//if (Distance > 300.f && Distance <= 500.f)
	//{
	//	DebugColor = FColor::Blue;
	//}
	//if (Distance > 500.f)
	//{
	//	DebugColor = FColor::Black;
	//}
	//DrawDebugLine(world, OwnerLocation, PlayerLocation, DebugColor, false);
	//UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), Distance)
	if (Distance >= Threshold)
	{
		return false;
	}
	else return true;
}


void AEternal_Grace_ArenaEnemy::BeginPlay()
{
	Super::BeginPlay();
	//if (HPBarComponent)
	//{
	//	UUserWidget* Widget = HPBarComponent->GetWidget();
	//	if (Widget)
	//	{
	//		HealthbarWidget = Cast<UEnemy_UI_Healthbar>(Widget);
	//		if (HealthbarWidget == nullptr)
	//		{
	//			UE_LOG(LogTemp, Error, TEXT("%s Failed to cast WidgetProperty to Enemy_UI_Bar"), *GetName())
	//		}
	//	}
	//	else
	//	{
	//		UE_LOG(LogTemp, Error, TEXT("Get Widget Function of %s HPBarComponent failed"), *GetName())
	//	}
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Error, TEXT("HP-Bar Component for %s is nullptr"), *GetName())
	//}



//	if(HealthbarWidgetClass)
//	{
//		HealthbarWidget = CreateWidget<UEnemy_UI_Healthbar>(GetWorld(), HealthbarWidgetClass);
//	}
//	if (HealthbarWidget)
//	{
//		HealthbarWidget->AddToViewport();
//		UE_LOG(LogTemp, Error, TEXT("HealthbarWidget Added"))
//	}
//	else
//	{
//		UE_LOG(LogTemp, Error, TEXT("No HealthbarWidget"))
//	}






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
	HideHealthWidget();
	Super::Die_Implementation();
	SendInfoToGameInstance();

	AAIController* EnemyAIController = UAIBlueprintHelperLibrary::GetAIController(this);
	if (EnemyAIController)
	{
		UBlackboardComponent* EnemyBlackboard = EnemyAIController->GetBlackboardComponent();

		if (EnemyBlackboard)
		{
			EnemyBlackboard->SetValueAsBool("isAlive", false);
		}
	}

	ACustomPlayerController* PlayerController = Cast<ACustomPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(PlayerController)
	{
		AEternal_Grace_ArenaCharacter* LockedOnTarget = PlayerController->GetLockOnSystem()->GetLockedOnTarget();
		if(LockedOnTarget && LockedOnTarget == this)
		{
			PlayerController->ToggleLockOn();
		}
	}



}

void AEternal_Grace_ArenaEnemy::LightAttack()
{
	if (!CharacterAnimationInstance->isAttacking)
	{
		TArray<UAnimMontage*> Attacks = WeaponComponent->GetCurrentLightAttacks();

		CharacterAnimationInstance->isAttacking = true;
		RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(world, 0));

		int RandomAttackIndex = UKismetMathLibrary::RandomInteger(Attacks.Num()); //CHANGE THIS TO LENGTH OF VIABLE ATTACK ARRAY

		PlayAnimMontage(Attacks[RandomAttackIndex], 1.0f);

		FOnMontageEnded InterruptDelegate;
		FOnMontageEnded CompletedDelegate;

		InterruptDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::InterruptAttack);
		CompletedDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::OnAttackEnd);

		CharacterAnimationInstance->Montage_SetBlendingOutDelegate(InterruptDelegate, Attacks[RandomAttackIndex]);
		CharacterAnimationInstance->Montage_SetEndDelegate(CompletedDelegate, Attacks[RandomAttackIndex]);

	}
}

void AEternal_Grace_ArenaEnemy::SpotPlayer(APawn* SpottedPawn)
{
	if (!isAggro)
	{
		isAggro = true;

		UE_LOG(LogTemp, Warning, TEXT("Enemy Spotted Player"))
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

void AEternal_Grace_ArenaEnemy::GetInfoFromGameInstance()
{
	//INSERT HERE IF THIS ENEMY RETREIVES ANY GAMEINSTANCE INFORMATION
}

bool AEternal_Grace_ArenaEnemy::CheckIfPlayerIsBehind()
{
	//	FColor DebugColor = FColor::Red;

	FVector OwnerLocation = GetActorLocation();
	FVector OwnerForwardDirection = GetActorForwardVector();
	FVector PlayerLocation = UGameplayStatics::GetPlayerCharacter(world, 0)->GetActorLocation();

	FVector OwnerPlayerDistance = PlayerLocation - OwnerLocation;
	OwnerPlayerDistance.Normalize();

	float dotproduct = UKismetMathLibrary::Dot_VectorVector(OwnerPlayerDistance, OwnerForwardDirection);

	//	DrawDebugLine(world, OwnerLocation, PlayerLocation, DebugColor, true);


	if (dotproduct < BackDetection)
	{
		//	DebugColor = FColor::Green;
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

void AEternal_Grace_ArenaEnemy::ShowHealthWidget()
{
	if (HealthbarWidget)
	{
		if (HealthbarWidget->IsInViewport())
		{
			return;
		}
		HealthbarWidget->AddToViewport();
		UWidgetAnimation* BlendInAnimation = HealthbarWidget->GetBlendInAnimation();
		if (BlendInAnimation)
		{
			HealthbarWidget->PlayAnimation(BlendInAnimation);
		}
		if (HealthbarWidget->GetBlendOutAnimation()) //BIND BLENDOUT ANIMATION TO REMOVE FROM VIEWPORT IN WIDGET
		{
			FWidgetAnimationDynamicEvent EndDelegate;
			EndDelegate.BindDynamic(HealthbarWidget, &UAnimatedWidget::BlendOut);
			HealthbarWidget->BindToAnimationFinished(HealthbarWidget->GetBlendOutAnimation(), EndDelegate);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No HealthbarWidget"))
	}
}

void AEternal_Grace_ArenaEnemy::HideHealthWidget()
{
	if (HealthbarWidget)
	{
		UWidgetAnimation* BlendOutAnimation = HealthbarWidget->GetBlendOutAnimation();
		if (BlendOutAnimation)
		{
			HealthbarWidget->PlayAnimation(BlendOutAnimation);
		}
	}
}
