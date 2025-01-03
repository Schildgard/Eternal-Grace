// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AInteractableActor::AInteractableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultRadiusSize = 200.0f;
	InfoClass = nullptr;
	InteractInfoWidget = nullptr;

	InteractionRadius = CreateDefaultSubobject<USphereComponent>("Interaction Radius");
	InteractionRadius->InitSphereRadius(DefaultRadiusSize); // Default Radius
	InteractionRadius->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InteractionRadius->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	InteractionRadius->SetHiddenInGame(false);
	InteractionRadius->bDrawOnlyIfSelected = true;

	RootComponent = InteractionRadius;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetupAttachment(RootComponent);
}

void AInteractableActor::Interact_Implementation()
{
//NOT SURE IF THIS ACTUALLY WORKS OR DOES ANYTHING
}

void AInteractableActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		Execute_Interact(this);
	}
}

void AInteractableActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//ADD LOGIC TO LEAVE RADIUS HERE
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

