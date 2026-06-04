// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/BreakerWidgetController.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnNotifyHpChanged, float, CurrentHealth, float, MaxHealth, float, HealthDelta);

UCLASS()
class BREAKER_API UOverlayWidgetController : public UBreakerWidgetController
{
	GENERATED_BODY()

public:
	virtual void Initialize() override;

	UPROPERTY(BlueprintAssignable, Category = "UI")
	FOnNotifyHpChanged OnNotifyHpChanged;

private:
	void HandleHpChanged(float CurrentHP, float MaxHP, float HealthDelta);
};
