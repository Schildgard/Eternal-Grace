// Fill out your copyright notice in the Description page of Project Settings.


#include "NS_PlayFootstepSound.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


void UNS_PlayFootstepSound::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	//Check Groundmaterial
	UPhysicalMaterial* UndergroundMaterial = CheckGroundMaterial(MeshComp);

	if (!UndergroundMaterial)
	{
		return;
	}
	//Choose sound by Index dependant on GroundMaterial
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
	}


	//SOUND MUST BE ONESHOT
	if (!Sounds[SoundsIndex]->IsOneShot())
	{
		UE_LOG(LogAudio, Warning, TEXT("Footstep sound is no Oneshot. Playing supressed."));
		return;
	}


	//IF PLAYED IN EDITOR
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

UPhysicalMaterial* UNS_PlayFootstepSound::CheckGroundMaterial(USkeletalMeshComponent* MeshComp)
{
	FVector ActorLocation = MeshComp->GetComponentLocation();
	FVector ScanDirection = FVector(ActorLocation.X, ActorLocation.Y, ActorLocation.Z - ScanDistance);
	FHitResult OutHit;
	UWorld* world = MeshComp->GetWorld();

	bool Hit = UKismetSystemLibrary::LineTraceSingle(world, ActorLocation, ScanDirection, UEngineTypes::ConvertToTraceType(ECC_Visibility), true, {}, EDrawDebugTrace::None, OutHit, true);

	if (!Hit)
	{
		return nullptr;
	}
	UPhysicalMaterial* HitMaterial = OutHit.PhysMaterial.Get();
	return HitMaterial;
}
