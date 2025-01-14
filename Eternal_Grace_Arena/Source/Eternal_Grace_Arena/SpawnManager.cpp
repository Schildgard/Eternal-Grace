// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnManager.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

}

void ASpawnManager::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);


	// Optional: Automatische Namensgebung
	for (int i = 0; i < SpawnPositions.Num(); i++)
	{
		if (SpawnPositions[i])
		{
		//	SpawnPositions[i]->SetRelativeLocation(FVector(i * 100.f, 0.f, 0.f)); // Anordnung im Editor
		//	SpawnPositions[i]->Rename(*FString::Printf(TEXT("SpawnPoint_%d"), i));

		}
	//else
	//{
	//	USceneComponent* SpawnPoint = CreateDefaultSubobject<USceneComponent>(*FString::Printf(TEXT("Spawnpoint_%d"),i));
	//	SpawnPoint->SetupAttachment(Root);
	//	SpawnPositions.Add(SpawnPoint);
	//	SpawnPoint->SetRelativeLocation(FVector(1 * 100.0f, 0.0f, 0.0f));
	//}
	}

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




FVector ASpawnManager::GetPositionRandom()
{
	//int SpawnPositionIndex = UKismetMathLibrary::RandomInteger(SpawnPositions.Num());
	//return SpawnPositions[SpawnPositionIndex]->GetComponentLocation();

	int SpawnPositionIndex = UKismetMathLibrary::RandomInteger(SpawnPositionActors.Num());
	return SpawnPositionActors[SpawnPositionIndex]->GetActorLocation();
}

FVector ASpawnManager::GetPosition(int SpawnPositionIndex)
{
	return SpawnPositionActors[SpawnPositionIndex]->GetActorLocation();
}

void ASpawnManager::AddSpawnPosition()
{
	USceneComponent* NewSpawnPosition = NewObject<USceneComponent>(this, USceneComponent::StaticClass());
	NewSpawnPosition->SetupAttachment(Root);
	SpawnPositions.Add(NewSpawnPosition);

	NewSpawnPosition->RegisterComponent();


}

