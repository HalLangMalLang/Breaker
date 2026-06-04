// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BreakerPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BREAKER_API ABreakerPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void OnPossess(APawn* InPawn) override;
};
