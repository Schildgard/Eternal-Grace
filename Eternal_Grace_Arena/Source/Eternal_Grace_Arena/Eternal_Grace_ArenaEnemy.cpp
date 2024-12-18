// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ArenaEnemy.h"

AEternal_Grace_ArenaEnemy::AEternal_Grace_ArenaEnemy()
{
	//UIClass = nullptr;
	//HBBar = nullptr;
	HPBarComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HP Bar"));
	HPBarComponent->SetupAttachment(RootComponent);
	HPBarComponent->SetWidgetSpace(EWidgetSpace::Screen);
	HPBarComponent->SetRelativeLocation(FVector(0, 0, 163.0f));
}

void AEternal_Grace_ArenaEnemy::BeginPlay()
{
	Super::BeginPlay();
	//if(UIClass != nullptr)
	//{
	//	HBBar = CreateWidget<UUserWidget>(GetWorld(), UIClass);
	//	HBBar->AddToViewport();
	//}

	//TODO:: SET UP SETTINGS IN C** INSTEAD OF BLUEPRINT
}
