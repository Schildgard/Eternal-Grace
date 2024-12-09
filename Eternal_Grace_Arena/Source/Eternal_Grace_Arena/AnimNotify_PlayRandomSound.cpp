// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_PlayRandomSound.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include <Kismet/GameplayStatics.h>
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

void UAnimNotify_PlayRandomSound::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	PRAGMA_DISABLE_DEPRECATION_WARNINGS
			Super::Notify(MeshComp, Animation);
		PRAGMA_ENABLE_DEPRECATION_WARNINGS

	UPhysicalMaterial* UndergroundMaterial = CheckGroundMaterial(MeshComp);

	int SoundsIndex = 0;


	switch (UndergroundMaterial->SurfaceType)
	{
	case SurfaceType1:
		SoundsIndex = 0;
		break;
	case SurfaceType2:
		SoundsIndex = 1;
		break;
	case SurfaceType3:
		SoundsIndex = 2;
		break;
	case SurfaceType4:
		SoundsIndex = 3;
		break;
	case SurfaceType_Default:
		return;
		break;
	}

	if (!UndergroundMaterial)
	{
		UE_LOG(LogTemp, Warning, TEXT("No UndergroundMaterial"))
			return;
	}
		// Don't call super to avoid call back in to blueprints
		if (Sounds.Num()>0 && MeshComp)
		{
			if (!Sounds[0]->IsOneShot()) //DOES NOT MAKE A LOT OF SENSE HERE
			{
				UE_LOG(LogAudio, Warning, TEXT("PlaySound notify: Anim %s tried to play a sound asset which is not a one-shot: '%s'. Spawning suppressed."), *GetNameSafe(Animation), *GetNameSafe(Sound));
				return;
			}

#if WITH_EDITORONLY_DATA
			UWorld* World = MeshComp->GetWorld();
			if (bPreviewIgnoreAttenuation && World && World->WorldType == EWorldType::EditorPreview)
			{
				if (MeshComp->IsPlaying())
				{
					UGameplayStatics::PlaySound2D(World, Sounds[SoundsIndex], VolumeMultiplier, PitchMultiplier);
				}
			}
			else
#endif
			{
				if (bFollow)
				{
					UGameplayStatics::SpawnSoundAttached(Sounds[SoundsIndex], MeshComp, AttachName, FVector(ForceInit), EAttachLocation::SnapToTarget, false, VolumeMultiplier, PitchMultiplier);
				}
				else
				{
					UGameplayStatics::PlaySoundAtLocation(MeshComp->GetWorld(), Sounds[SoundsIndex], MeshComp->GetComponentLocation(), VolumeMultiplier, PitchMultiplier);
				}
			}
		}
}

UPhysicalMaterial* UAnimNotify_PlayRandomSound::CheckGroundMaterial(USkeletalMeshComponent* MeshComp)
{
	// CONTINUE TO WORK HERE
	FVector ActorLocation = MeshComp->GetComponentLocation();
	FVector ScanDirection = FVector(ActorLocation.X, ActorLocation.Y, ActorLocation.Z - ScanDistance);
	FHitResult OutHit;
	UWorld* world = MeshComp->GetWorld();

	bool Hit = UKismetSystemLibrary::LineTraceSingle(world, ActorLocation, ScanDirection, UEngineTypes::ConvertToTraceType(ECC_Visibility), true, {}, EDrawDebugTrace::ForDuration, OutHit, true, FLinearColor::Red, FLinearColor::Green, 5.0f);

	if (Hit)
	{
		UPhysicalMaterial* HitMaterial = OutHit.PhysMaterial.Get();
		UE_LOG(LogTemp, Warning, TEXT("Found PhysMaterial"))
		return HitMaterial;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AnimNotify PlayRandomSound Tried to Scan for PhysicMaterial on Ground but found none"))

			return nullptr;
	}
}


