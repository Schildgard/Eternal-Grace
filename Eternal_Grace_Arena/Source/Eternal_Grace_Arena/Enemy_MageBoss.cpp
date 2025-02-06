// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_MageBoss.h"
#include "CharacterAnimInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet//KismetMathLibrary.h"
#include "SpawnPoint.h"
#include "SpellComponent.h"

AEnemy_MageBoss::AEnemy_MageBoss()
{
	SpellComponent = CreateDefaultSubobject<USpellComponent>("Spells");
}

void AEnemy_MageBoss::LightAttack()
{
	if (!CharacterAnimationInstance->isAttacking)
	{
		TArray<UAnimMontage*> Spells = SpellComponent->GetSpellList();
		CharacterAnimationInstance->isAttacking = true;
		int SpellIndex = 0; //FIREBALL

		// CHECK IF PLAYER IS IN TELEPORT RANGE
		if (CheckDistancetoPlayer(350.0f))
		{
			SetTeleportPosition();
			SpellIndex = 1; //TELEPORT
		}
		else if (SecondPhaseTriggered)
		{
			SpellIndex = 2; //HOMING FIREBALL
		}


		RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(world, 0));
		FOnMontageEnded InterruptDelegate;
		FOnMontageEnded CompletedDelegate;

		PlayAnimMontage(Spells[SpellIndex], 1.0f); //CHANGE THIS TO FLEXIBLE ARRAY INDEX OF VIABLE ATTACKS
		InterruptDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::InterruptAttack);
		CompletedDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::OnAttackEnd);

		CharacterAnimationInstance->Montage_SetBlendingOutDelegate(InterruptDelegate, Spells[SpellIndex]);
		CharacterAnimationInstance->Montage_SetEndDelegate(CompletedDelegate, Spells[SpellIndex]);
	}
}

void AEnemy_MageBoss::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(!CharacterAnimationInstance->isAttacking && isAggro)
	{
		RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(world, 0));
	}
}

void AEnemy_MageBoss::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> PositionActors;
	// TODO: REFACTOR THIS INTO A DICTIONARY SO THIS STILL WORKS IF THE SCENE HAS MULTIPLE SPAWNMANAGERS
	UGameplayStatics::GetAllActorsOfClass(world, ASpawnPoint::StaticClass(), PositionActors);

	if (PositionActors.Num() > 0)
	{
		for (AActor* Position : PositionActors)
		{
			ASpawnPoint* SpawnPosition = Cast<ASpawnPoint>(Position);
			if (SpawnPosition)
			{
				SpawnPositions.Add(SpawnPosition);
				AvaiableSpawnPositions.Add(SpawnPosition);
			}
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s Could not find SpawnPositions in Level on BeginPlay. Teleportation wont work"), *GetName())
	}
}

void AEnemy_MageBoss::SetTeleportPosition()
{
	if (AvaiableSpawnPositions.Num() <= 0)
	{
		//RESET AVAIABLE LIST
		AvaiableSpawnPositions = SpawnPositions;
	}

	//GET RANDOM SPAWNPOSITION
	int RandomIndex = UKismetMathLibrary::RandomInteger(AvaiableSpawnPositions.Num());
	//SET TELEPORT POSITION
	FVector TargetLocation = AvaiableSpawnPositions[RandomIndex]->GetActorLocation();
	SpellComponent->SetTargetPosition(TargetLocation);
	// SAFEREMOVE POSITION FROM AVAIABLE LIST
	AvaiableSpawnPositions.RemoveAt(RandomIndex);
}

USpellComponent* AEnemy_MageBoss::GetSpellComponent()
{
	return SpellComponent;
}
