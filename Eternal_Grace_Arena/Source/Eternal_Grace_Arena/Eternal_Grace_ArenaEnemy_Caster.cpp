// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ArenaEnemy_Caster.h"
#include "SpellComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "SpawnPoint.h"

AEternal_Grace_ArenaEnemy_Caster::AEternal_Grace_ArenaEnemy_Caster()
{
	SpellComponent = CreateDefaultSubobject<USpellComponent>("Spells");
}

void AEternal_Grace_ArenaEnemy_Caster::Test_PlayCastAnim()
{
	if (CastAnimTest)
	{
		PlayAnimMontage(CastAnimTest, 1.0f);
	}
}

void AEternal_Grace_ArenaEnemy_Caster::CastTeleport()
{
	//TODO: CHANGE THIS FUNCTION SO IT ONLY GETS VIABLE SPAWNPOSITIONS. THE ACTUAL CAST OF THE SPELL HAPPENS IN CAST SPELL.
	if (SpawnPositions.Num() >= 1)
	{
		int RandomIndex = UKismetMathLibrary::RandomInteger(SpawnPositions.Num());

		FVector TargetLocation = SpawnPositions[RandomIndex]->GetActorLocation();
		SpellComponent->SetTargetPosition(TargetLocation);
		PlayAnimMontage(TeleportAnim);

		// NOT USED YET
		BlockedSpawnPositions.Add(SpawnPositions[RandomIndex]);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No Position to Teleport"))
	}
}

void AEternal_Grace_ArenaEnemy_Caster::CastSpell()
{
	if (SpellComponent)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = this;

		if (SpellComponent->SpellList.Num() > 0)
		{
			ASpell* SpellCast = GetWorld()->SpawnActor<ASpell>(SpellComponent->SpellList[0], GetActorLocation(), GetActorRotation(), SpawnParams);
		}
	}
}

USpellComponent* AEternal_Grace_ArenaEnemy_Caster::GetSpellComponent()
{
	return SpellComponent;
}

void AEternal_Grace_ArenaEnemy_Caster::BeginPlay()
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
		UE_LOG(LogTemp, Warning, TEXT("Caster has %d Spawnpositions"), SpawnPositions.Num())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Caster could not get SpawnManager. Teleportation wont work"))
	}

}

void AEternal_Grace_ArenaEnemy_Caster::Tick(float DeltaSeconds)
{

	Super::Tick(DeltaSeconds);
}
