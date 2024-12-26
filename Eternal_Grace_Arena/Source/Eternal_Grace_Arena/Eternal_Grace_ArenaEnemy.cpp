// Fill out your copyright notice in the Description page of Project Settings.


#include "Eternal_Grace_ArenaEnemy.h"
#include "CharacterAnimInstance.h"

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
				HealthbarWidget = Cast<UEnemy_UI_Healthbar>(Widget);
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
		if (HealthComponent)
		{
			HealthbarWidget->UpdateProgressBar(HealthbarWidget->Healthbar, HealthComponent->MaxHealth, HealthComponent->CurrentHealth);
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

void AEternal_Grace_ArenaEnemy::LightAttack()
{
	if (!CharacterAnimationInstance->isAttacking)
	{
		CharacterAnimationInstance->isAttacking = true;
		if (CharacterAnimationInstance->isGuarding)
		{
			CancelGuard();
		}
		PlayAnimMontage(LightAttacks[0], 1.0f, "Attack01");

		switch (CharacterAnimationInstance->attackCount)
		{
		case 0:
			break;
		case 1:
			CharacterAnimationInstance->Montage_JumpToSection("Attack02", LightAttacks[0]);
			break;
		case 2:
			CharacterAnimationInstance->Montage_JumpToSection("Attack03", LightAttacks[0]);
			break;
		default:
			break;
		}
		FOnMontageEnded InterruptDelegate;
		InterruptDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::InterruptAttack);
		CharacterAnimationInstance->Montage_SetBlendingOutDelegate(InterruptDelegate, LightAttacks[0]);

		FOnMontageEnded CompletedDelegate;
		CompletedDelegate.BindUObject(CharacterAnimationInstance, &UCharacterAnimInstance::OnAttackEnd);
		CharacterAnimationInstance->Montage_SetEndDelegate(CompletedDelegate, LightAttacks[0]);
	}
}
