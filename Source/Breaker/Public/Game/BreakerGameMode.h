// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Subsystem/ObjectPool/PoolTypes.h"
#include "BreakerGameMode.generated.h"

UCLASS()
class BREAKER_API ABreakerGameMode : public AGameMode
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FName, FPooledObjectData> PooledObjectData;

	virtual void BeginPlay() override;
};
