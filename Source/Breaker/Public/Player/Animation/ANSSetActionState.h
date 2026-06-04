// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Types/BreakerPlayerTypes.h"
#include "ANSSetActionState.generated.h"

/**
 * 
 */
UCLASS()
class BREAKER_API UANSSetActionState : public UAnimNotifyState
{
	GENERATED_BODY()
protected:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	EActionState StateToSet;
};
