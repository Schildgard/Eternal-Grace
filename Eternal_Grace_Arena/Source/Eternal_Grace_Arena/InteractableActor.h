// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "I_Interactable.h"
#include "InteractableActor.generated.h"

class UEternalGrace_GameInstance;
class UNiagaraComponent;
class USphereComponent;
class UAnimatedWidget;
UCLASS()
class ETERNAL_GRACE_ARENA_API AInteractableActor : public AActor, public II_Interactable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableActor();

	virtual void Interact_Implementation()override;
	// COSTUM OVERLAP FUNCTION IMPLEMENTATION SINCE AACTOR BASE CLASS HAS NO DECLARATION FOR IT
	UFUNCTION()
	virtual void OnBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);
	UFUNCTION()
	virtual void OnOverlapEnd(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex
	);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction")
	USphereComponent* InteractionRadius;
	UPROPERTY()
	float DefaultRadiusSize;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> InfoClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	UAnimatedWidget* InteractInfoWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
	UNiagaraComponent* NiagaraEffect;
	


	//COMMUNICATION WITH GAME INSTANCE
	UPROPERTY()
	UEternalGrace_GameInstance* ActiveGameInstance;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scene Loading", meta = (AllowPrivateAccess))
	bool isActive;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	FName UniqueID;

	UFUNCTION()
	void UpdateStatus();



	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	bool GetActiveStatus();

};
