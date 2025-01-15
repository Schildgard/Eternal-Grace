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
		CharacterAnimationInstance->isAttacking = true;
		int AttackIndex = 0;
		// CHECK IF PLAYER IS IN TELEPORT RANGE
		if (CheckDistancetoPlayer(350.0f))
		{
			AttackIndex = 1;
			SetTeleportPosition();
		}
		RotateTowardsTarget(UGameplayStatics::GetPlayerCharacter(world, 0));

		FOnMontageEnded InterruptDelegate;
		FOnMontageEnded CompletedDelegate;

		PlayAnimMontage(LightAttacks[AttackIndex], 1.0f); //CHANGE THIS TO FLEXIBLE ARRAY INDEX OF VIABLE ATTACKS
		InterruptDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::InterruptAttack);
		CompletedDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::OnAttackEnd);

		CharacterAnimationInstance->Montage_SetBlendingOutDelegate(InterruptDelegate, LightAttacks[AttackIndex]);
		CharacterAnimationInstance->Montage_SetEndDelegate(CompletedDelegate, LightAttacks[AttackIndex]);
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
	if (SpawnPositions.Num() >= 1)
	{
		//GET SPAWN POSITION INDEX
		int RandomIndex = UKismetMathLibrary::RandomInteger(SpawnPositions.Num());

		// IF THERE A AT LEAST 2 SPAWN POSITIONS, BLOCK THE CURRENT POSITION - kinda bullshit, i am sure there is a better way to do it
		if (SpawnPositions.Num() >= 2)
		{
			BlockedSpawnPositionsIndices.Add(RandomIndex);

		}

		// IF POSITION IS BLOCKED, REPEAT THIS PROCESS RECURSIVELY UNTIL YOU FOUND ANOTHER POSITION
//		if(BlockedSpawnPositionsIndices.Contains(RandomIndex))
//		{
//			SetTeleportPosition();
//		}
		BlockedSpawnPositionsIndices.Empty();

		FVector TargetLocation = SpawnPositions[RandomIndex]->GetActorLocation();
		SpellComponent->SetTargetPosition(TargetLocation);

	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Position to Teleport"))
	}
}

USpellComponent* AEnemy_MageBoss::GetSpellComponent()
{
	return SpellComponent;
}
