// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Animation/ANSSetActionState.h"
#include "Player/Character/BreakerCharacter.h"

void UANSSetActionState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
    Super::NotifyBegin(MeshComp, Animation, TotalDuration);

    if (MeshComp && MeshComp->GetOwner())
    {
        if (ABreakerCharacter* BreakerCharacter = Cast<ABreakerCharacter>(MeshComp->GetOwner()))
        {
            BreakerCharacter->SetActionState(StateToSet);
        }
    }
}

void UANSSetActionState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
    Super::NotifyEnd(MeshComp, Animation);

    if (MeshComp && MeshComp->GetOwner())
    {
        if (ABreakerCharacter* BreakerCharacter = Cast<ABreakerCharacter>(MeshComp->GetOwner()))
        {
            BreakerCharacter->SetActionState(EActionState::Idle);
        }
    }
}
