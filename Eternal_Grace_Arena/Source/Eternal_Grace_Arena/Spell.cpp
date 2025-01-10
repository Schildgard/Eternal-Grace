// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "Eternal_Grace_ArenaCharacter.h"

// Sets default values
ASpell::ASpell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HitBox = CreateDefaultSubobject<USphereComponent>("HitBox");
	RootComponent = HitBox;
	SpellVFX = CreateDefaultSubobject<UNiagaraComponent>("Spell Effect");
	SpellVFX->SetupAttachment(RootComponent);

	ValidCharacterClass = nullptr;

}

// Called when the game starts or when spawned
void ASpell::BeginPlay()
{
	Super::BeginPlay();
	HitBox->OnComponentBeginOverlap.AddDynamic(this, &ASpell::SpellEffect);
	UE_LOG(LogTemp, Warning, TEXT("%s was casted"), *GetName())
}

void ASpell::SpellEffect(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,UPrimitiveComponent* OtherComponent,int32 OtherBodyIndex,bool bFromSweep,const FHitResult& SweepResult)
{
	AActor* InstignatingActor = GetInstigator();
		if (ValidCharacterClass == nullptr)
		{
			return;
		}
//if(OnHitVFX)
//{
//UNiagaraFunctionLibrary::SpawnSystemAttached(OnHitVFX, OtherComponent, NAME_None, FVector(0.0f), FRotator(0.0f), EAttachLocation::KeepRelativeOffset, true);
//}
		//if (OtherActor && OtherActor->IsA(ValidCharacterClass))
		//{
		//	AEternal_Grace_ArenaCharacter* HittedCharacter = Cast<AEternal_Grace_ArenaCharacter>(OtherActor);
		//	if(HittedCharacter)
		//	{
		//		UE_LOG(LogTemp, Warning, TEXT("%s hitted"), *GetName(), *HittedCharacter->GetName())
		//	}
		//}
}

// Called every frame
void ASpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

