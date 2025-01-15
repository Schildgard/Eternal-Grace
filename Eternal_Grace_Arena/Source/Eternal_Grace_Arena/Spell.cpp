// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "Eternal_Grace_ArenaCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values
ASpell::ASpell()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HitBox = CreateDefaultSubobject<USphereComponent>("HitBox");
	//HitBox->SetupAttachment(RootComponent);
	RootComponent = HitBox;
	SpellVFX = CreateDefaultSubobject<UNiagaraComponent>("Spell Effect");
	SpellVFX->SetupAttachment(RootComponent);

	InstigatingActor = nullptr;

	ValidCharacterClass = nullptr;

}

void ASpell::BeginPlay()
{
	Super::BeginPlay();

	HitBox->OnComponentBeginOverlap.AddDynamic(this, &ASpell::SpellEffect);

	if (SpawningSound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), SpawningSound, GetActorLocation(), 1.0f);
	}

	InstigatingActor = Cast<AEternal_Grace_ArenaCharacter>(GetInstigator());
	if (!InstigatingActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s could not get Instigating Character"), *GetName())
			return;
	}
	if (LoopSound)
	{
		UGameplayStatics::SpawnSoundAttached(LoopSound, InstigatingActor->GetRootComponent(), NAME_None, FVector(0.0f), EAttachLocation::SnapToTarget, true, true);
	}

}

void ASpell::SpellEffect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ValidCharacterClass == nullptr)
	{
		return;
	}

}

// Called every frame
void ASpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

