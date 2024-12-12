// Fill out your copyright notice in the Description page of Project Settings.


#include "GA_GetDamage.h"
#include "Eternal_Grace_ArenaCharacter.h"

void UGA_GetDamage::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    if (!HasAuthorityOrPredictionKey(ActorInfo, &ActivationInfo))
    {
        EndAbility(Handle, ActorInfo, ActivationInfo, true, false);
        return;
    }

    // Überprüfen, ob die Montage gesetzt ist
    if (MontageToPlay && ActorInfo->AvatarActor.IsValid())
    {
        AEternal_Grace_ArenaCharacter* Character = Cast<AEternal_Grace_ArenaCharacter>(ActorInfo->AvatarActor.Get());
        if (Character && Character->GetMesh())
        {
            // Montage abspielen
            Character->PlayAnimMontage(MontageToPlay);
        }
    }
    // Ability beenden
    EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}
