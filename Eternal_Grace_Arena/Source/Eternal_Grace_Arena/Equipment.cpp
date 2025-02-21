// Fill out your copyright notice in the Description page of Project Settings.


#include "Equipment.h"

// Sets default values
AEquipment::AEquipment()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
}

void AEquipment::BeginPlay()
{
	Super::BeginPlay();
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Mesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	
}

void AEquipment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UStaticMeshComponent* AEquipment::GetMesh()
{
	return Mesh;
}

