// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/BreakerWidgetController.h"
#include "InteractionWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNotifyTargetItemChanged, const FString&, ItemName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNotifyItemAcquired, const FString&, ItemName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNotifyInteractionProgressChanged, float, Percent);

UCLASS()
class BREAKER_API UInteractionWidgetController : public UBreakerWidgetController
{
	GENERATED_BODY()
	
public:
	virtual void Initialize() override;

	UPROPERTY(BlueprintAssignable, Category = "Breaker|Interaction")
	FOnNotifyTargetItemChanged OnNotifyTargetItemChanged;

	UPROPERTY(BlueprintAssignable, Category = "Breaker|Interaction")
	FOnNotifyItemAcquired OnNotifyItemAcquired;

	UPROPERTY(BlueprintAssignable, Category = "Breaker|Interaction")
	FOnNotifyInteractionProgressChanged OnNotifyInteractionProgressChanged;

private:
	UFUNCTION()
	void HandleTargetItemChanged(const FString& ItemName);
	UFUNCTION()
	void HandleItemAcquired(const FString& ItemName);
	UFUNCTION()
	void HandleInteractionProgressChanged(float Percent);
};
