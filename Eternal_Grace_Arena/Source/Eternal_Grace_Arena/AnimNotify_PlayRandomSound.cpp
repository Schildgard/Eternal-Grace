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
		// Don't call super to avoid call back in to blueprints
		if (Sound && MeshComp)
		{
			if (!Sound->IsOneShot())
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
					UGameplayStatics::PlaySound2D(World, Sounds[UKismetMathLibrary::RandomIntegerInRange(0, 5)], VolumeMultiplier, PitchMultiplier);
				}
			}
			else
#endif
			{
				if (bFollow)
				{
					UGameplayStatics::SpawnSoundAttached(Sounds[UKismetMathLibrary::RandomIntegerInRange(0, 5)], MeshComp, AttachName, FVector(ForceInit), EAttachLocation::SnapToTarget, false, VolumeMultiplier, PitchMultiplier);
				}
				else
				{
					UGameplayStatics::PlaySoundAtLocation(MeshComp->GetWorld(), Sounds[UKismetMathLibrary::RandomIntegerInRange(0, 5)], MeshComp->GetComponentLocation(), VolumeMultiplier, PitchMultiplier);
				}
			}
		}
}

UPhysicalMaterial* UAnimNotify_PlayRandomSound::CheckGroundMaterial()
{
	// CONTINUE TO WORK HERE
	USkeletalMeshComponent* ActorMesh = nullptr;
	FVector ActorLocation = ActorMesh->GetComponentLocation();
	FVector ScanDirection = FVector(ActorLocation.X, ActorLocation.Y, ActorLocation.Z - 200.0f);
	FHitResult OutHit;

	bool Hit = UKismetSystemLibrary::LineTraceSingle(GetWorld(), ActorLocation, ScanDirection, UEngineTypes::ConvertToTraceType(ECC_Visibility), true, {}, EDrawDebugTrace::None, OutHit, true);

	if (Hit)
	{
		UPhysicalMaterial* HitMaterial = OutHit.PhysMaterial.Get();
		return HitMaterial;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AnimNotify PlayRandomSound Tried to Scan for PhysicMaterial on Ground but found none"))

			return nullptr;
	}
}


