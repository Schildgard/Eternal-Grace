// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Components/WidgetComponent.h"
#include "Eternal_Grace_ArenaEnemy.generated.h"

/**
 * 
 */
UCLASS()
class ETERNAL_GRACE_ARENA_API AEternal_Grace_ArenaEnemy : public AEternal_Grace_ArenaCharacter
{
	GENERATED_BODY()
	
	AEternal_Grace_ArenaEnemy();
public:
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess))
//	TSubclassOf<UUserWidget> UIClass;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess))
//	UUserWidget* HBBar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, meta = (AllowPrivateAccess))
	UWidgetComponent* HPBarComponent;

protected:
	virtual void BeginPlay()override;
	
};
