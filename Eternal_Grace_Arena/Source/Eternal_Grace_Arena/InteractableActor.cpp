// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "EternalGrace_GameInstance.h"
#include "NiagaraComponent.h"

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

	NiagaraEffect = CreateDefaultSubobject<UNiagaraComponent>("Activation Effect");
	NiagaraEffect->SetupAttachment(RootComponent);
	NiagaraEffect->bAutoActivate = false; //NOT SURE IF THIS ACTUALLY DOES ANYTHING IN CONSTRUCTOR
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

void AInteractableActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{

}
//STATUS IS UPDATE ON BEGIN PLAY. THE ACTOR CHECKS THE OF THE GAME INSTANCE TO SET ITS PROPERTIES
void AInteractableActor::UpdateStatus()
{
	if (ActiveGameInstance && ActiveGameInstance->ObjectStates.Contains(UniqueID))
	{
		isActive = ActiveGameInstance->ObjectStates[UniqueID];
		if (isActive)
		{
			NiagaraEffect->Activate(true);
			UE_LOG(LogTemp, Warning, TEXT("%s is Active"), *GetName())
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("%s is not Active"), *GetName())
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s Could not Access GameInstance or GameInstance Dictionary did not Contained its key"), *GetName())
	}
}

// Called when the game starts or when spawned
void AInteractableActor::BeginPlay()
{
	Super::BeginPlay();

	InteractionRadius->OnComponentBeginOverlap.AddDynamic(this, &AInteractableActor::OnBeginOverlap);
	InteractionRadius->OnComponentEndOverlap.AddDynamic(this, &AInteractableActor::OnOverlapEnd);

	UGameInstance* CurrentInstance = UGameplayStatics::GetGameInstance(GetWorld());
	ActiveGameInstance = Cast<UEternalGrace_GameInstance>(CurrentInstance);
	if (ActiveGameInstance)
	{
		//SET IS ACTIVE DEPENDING ON DICTIONARY OF GAME INSTANCE
		ActiveGameInstance->OnObjectStateChange.AddDynamic(this, &AInteractableActor_SceneLoader::UpdateStatus);
		UpdateStatus();
	}

}

// Called every frame
void AInteractableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

