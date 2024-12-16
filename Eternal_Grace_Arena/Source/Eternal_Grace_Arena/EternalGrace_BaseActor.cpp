// Fill out your copyright notice in the Description page of Project Settings.


#include "EternalGrace_BaseActor.h"

// Sets default values
AEternalGrace_BaseActor::AEternalGrace_BaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEternalGrace_BaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEternalGrace_BaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

