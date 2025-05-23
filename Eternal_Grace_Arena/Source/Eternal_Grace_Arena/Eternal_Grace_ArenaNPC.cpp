// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ArenaNPC.h"
#include "Components/SphereComponent.h"
#include "DialogueComponent.h"


AEternal_Grace_ArenaNPC::AEternal_Grace_ArenaNPC()
{
	DefaultRadiusSize = 200.0f;

	InteractionRadius = CreateDefaultSubobject<USphereComponent>("Interaction Radius");
	InteractionRadius->InitSphereRadius(DefaultRadiusSize);
	InteractionRadius->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	InteractionRadius->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	InteractionRadius->SetHiddenInGame(false);
	InteractionRadius->bDrawOnlyIfSelected = true;

	InteractionRadius->SetupAttachment(RootComponent);

	isAggro = false;

	InfoClass = nullptr;
	InteractInfoWidget = nullptr;

	TextCounter = 0;

	DialogueComponent = CreateDefaultSubobject<UDialogueComponent>("Dialogue Component");
}

void AEternal_Grace_ArenaNPC::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{


		//SAME AS IN INTERACTABLE ACTOR-SCENELOADER
		UE_LOG(LogTemp, Warning, TEXT("Trigger Overlap"))
			if (InteractInfoWidget && !InteractInfoWidget->IsInViewport())
			{
				InteractInfoWidget->AddToViewport();
				if (InteractInfoWidget->GetBlendInAnimation())
				{
					InteractInfoWidget->PlayAnimation(InteractInfoWidget->GetBlendInAnimation());
				}
				if (InteractInfoWidget->GetBlendOutAnimation())
				{
					FWidgetAnimationDynamicEvent EndDelegate;
					EndDelegate.BindDynamic(InteractInfoWidget, &UAnimatedWidget::BlendOut);
					InteractInfoWidget->BindToAnimationFinished(InteractInfoWidget->GetBlendOutAnimation(), EndDelegate);
				}
			}
	}
}

void AEternal_Grace_ArenaNPC::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	if (InteractInfoWidget->GetBlendOutAnimation())
	{
		InteractInfoWidget->PlayAnimation(InteractInfoWidget->GetBlendOutAnimation());
	}
	if(DialogueComponent->DialogueWidget->IsInViewport())
	{
		DialogueComponent->DialogueWidget->PlayAnimation(DialogueComponent->DialogueWidget->GetBlendOutAnimation());
	}
}

void AEternal_Grace_ArenaNPC::BeginPlay()
{

	Super::BeginPlay();
	InteractionRadius->OnComponentBeginOverlap.AddDynamic(this, &AEternal_Grace_ArenaNPC::OnBeginOverlap);
	InteractionRadius->OnComponentEndOverlap.AddDynamic(this, &AEternal_Grace_ArenaNPC::OnOverlapEnd);

	if(!DialogueComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("DialogueComponent is nullptr"))
	}
}

void AEternal_Grace_ArenaNPC::Interact_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Trigger Talk"))
		// DEACTIVATE INTERACT WIDGET IF ACTIVE
		//ACTIVATE DIALOGUE WIDGET IF UNACTIVE
		//IF DIALOGUE WIDGET IS ACTIVE, REPLACE TEXT WITH NEXT TEXT OF TEXT ARRAY AND MARK THIS TEXT AS LISTENED TO
		//IF AT LAST INDEX, DEACTIVATE DIALOGOUE WIDGET

		if (InteractInfoWidget->IsInViewport())
		{
			InteractInfoWidget->PlayAnimation(InteractInfoWidget->GetBlendOutAnimation());
		}

	DialogueComponent->PlayDialogue();




}

