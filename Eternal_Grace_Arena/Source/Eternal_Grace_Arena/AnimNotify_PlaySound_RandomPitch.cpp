// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_PlaySound_RandomPitch.h"
#include "Audio.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Sound/SoundBase.h"
#include "Animation/AnimSequenceBase.h"

void UAnimNotify_PlaySound_RandomPitch::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
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
					UGameplayStatics::PlaySound2D(World, Sound, VolumeMultiplier, PitchMultiplier);
				}
			}
			else
#endif
			{
				if (bFollow)
				{
					UGameplayStatics::SpawnSoundAttached(Sound, MeshComp, AttachName, FVector(ForceInit), EAttachLocation::SnapToTarget, false, VolumeMultiplier, UKismetMathLibrary::RandomFloatInRange(minPitch, maxPitch));
				}
				else
				{
					UGameplayStatics::PlaySoundAtLocation(MeshComp->GetWorld(), Sound, MeshComp->GetComponentLocation(), VolumeMultiplier, UKismetMathLibrary::RandomFloatInRange(minPitch,maxPitch));
				}
			}
		}
}
