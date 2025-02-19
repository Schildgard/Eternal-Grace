// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableActor_SceneLoader.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"
#include "Blueprint/UserWidget.h"
#include "EternalGrace_GameInstance.h"
#include "AnimatedWidget.h"

AInteractableActor_SceneLoader::AInteractableActor_SceneLoader()
{
	ActiveGameInstance = nullptr;
	isActive = true;
}

void AInteractableActor_SceneLoader::Interact_Implementation()
{
	if (isActive)
	{
		//CHECK IF LEVEL TO LOAD IS ASSIGNED AND VALID
		if (LevelNameToLoad.IsNone())
		{
			UE_LOG(LogTemp, Warning, TEXT("%s tried to load into Level to Load but failed miserably. Its probably nullptr"), *GetName())
				return;
		}
		else
		{
			ActiveGameInstance->SetLevelToLoad(LevelNameToLoad);
			OnInteract.Broadcast();
		}
	}
	else
	{
		//INSERT NOTIFICATION THAT THE SCENE LOADING OBJECT IS UNACTIVE BECAUSE OF CONDITIONS IN GAMESTATE
		UE_LOG(LogTemp, Warning, TEXT("%s is not Active "), *GetName())
	}
}

void AInteractableActor_SceneLoader::BeginPlay()
{
	Super::BeginPlay();

	if (ActiveGameInstance)
	{
		OnInteract.AddDynamic(ActiveGameInstance, &UEternalGrace_GameInstance::OnMapLeave);
		FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(ActiveGameInstance, &UEternalGrace_GameInstance::OnMapEnter);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s failed to Cast to Custom GameInstance. Thus GameInstance could not Subscribe to its Interact Event"), *GetName())
	}
}

void AInteractableActor_SceneLoader::LoadLevel()
{
	if (!LevelNameToLoad.IsNone())
	{
		UGameplayStatics::OpenLevel(this, LevelNameToLoad);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s LoadLevel Function was called but LevelToLoad could not be getted."), *GetName())
	}
}

void AInteractableActor_SceneLoader::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (isActive && InteractInfoWidget && !InteractInfoWidget->IsInViewport())
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

void AInteractableActor_SceneLoader::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	if (InteractInfoWidget->GetBlendOutAnimation())
	{
		InteractInfoWidget->PlayAnimation(InteractInfoWidget->GetBlendOutAnimation());
	}
}
