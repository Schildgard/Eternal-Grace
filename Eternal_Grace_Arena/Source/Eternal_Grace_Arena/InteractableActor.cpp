// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor.h"

// Sets default values
AInteractableActor::AInteractableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	DefaultRadiusSize = 200.0f;

	InteractionRadius = CreateDefaultSubobject<USphereComponent>("Interaction Radius");
	InteractionRadius->InitSphereRadius(DefaultRadiusSize); // Default Radius
	InteractionRadius->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InteractionRadius->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	InteractionRadius->SetHiddenInGame(false);
	InteractionRadius->bDrawOnlyIfSelected = true;

	//RootComponent = InteractionRadius;
}

void AInteractableActor::Interact_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Interact called in AMyActor!"));
}

void AInteractableActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor && OtherActor!=this)
	{
		Interact();
	}
}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();

	InteractionRadius->OnComponentBeginOverlap.AddDynamic(this, &AInteractableActor::OnBeginOverlap);
	
}

// Called every frame
void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

