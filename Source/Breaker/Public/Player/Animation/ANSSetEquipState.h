// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Types/BreakerPlayerTypes.h"
#include "ANSSetEquipState.generated.h"

/**
 * 
 */
UCLASS()
class BREAKER_API UANSSetEquipState : public UAnimNotifyState
{
	GENERATED_BODY()

protected:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	EEquipState StateToSet;
};
