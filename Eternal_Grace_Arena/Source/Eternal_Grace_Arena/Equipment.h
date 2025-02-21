// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Equipment.generated.h"

UCLASS()
class ETERNAL_GRACE_ARENA_API AEquipment : public AActor
{
	GENERATED_BODY()
	
public:	
	AEquipment();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	UStaticMeshComponent* Mesh;
public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	UStaticMeshComponent* GetMesh();

};
