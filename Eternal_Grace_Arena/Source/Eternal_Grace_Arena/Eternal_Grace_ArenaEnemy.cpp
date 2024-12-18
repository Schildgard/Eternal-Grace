// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ArenaEnemy.h"

AEternal_Grace_ArenaEnemy::AEternal_Grace_ArenaEnemy()
{
	HPBarComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HP Bar"));
	HPBarComponent->SetupAttachment(RootComponent);
	HPBarComponent->SetWidgetSpace(EWidgetSpace::Screen);
	HPBarComponent->SetRelativeLocation(FVector(0, 0, 163.0f));

	HealthbarWidget = nullptr;
}

void AEternal_Grace_ArenaEnemy::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin"))
		if (HPBarComponent)
		{
			UUserWidget* Widget = HPBarComponent->GetWidget();
			if (Widget)
			{
				HealthbarWidget = Cast<UEternal_Grace_ProgressBar>(Widget);
				if (HealthbarWidget == nullptr)
				{
					UE_LOG(LogTemp, Warning, TEXT("Failed Widget to CustomProgressbar"))
				}
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("HBBar has no widget"))
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("HP Bar is null"))
		}
}

void AEternal_Grace_ArenaEnemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (HealthbarWidget)
	{
		if(HealthComponent)
		{
		HealthbarWidget->UpdateProgressBar(HealthComponent->MaxHealth, HealthComponent->CurrentHealth);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Health Component is null"))
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Healthbar widget is null"))
	}
}
