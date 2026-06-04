// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Animation/ANSSetEquipState.h"
#include "Player/Character/BreakerCharacter.h"

void UANSSetEquipState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
    Super::NotifyBegin(MeshComp, Animation, TotalDuration);

    if (MeshComp && MeshComp->GetOwner())
    {
        if (ABreakerCharacter* BreakerCharacter = Cast<ABreakerCharacter>(MeshComp->GetOwner()))
        {
            BreakerCharacter->SetEquipState(StateToSet);
        }
    }
}
