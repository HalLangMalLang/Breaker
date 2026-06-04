// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BreakerHUD.generated.h"

class UBreakerUserWidget;
class UOverlayWidgetController;
class UInteractionWidgetController;
class UPlayerStatComponent;
class UBreakerWidgetController;
struct FWidgetControllerParams;

UCLASS()
class BREAKER_API ABreakerHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	TObjectPtr<UBreakerUserWidget> OverlayWidget;

	UPROPERTY()
	TObjectPtr<UBreakerUserWidget> InteractionWidget;

	UBreakerWidgetController* GetWidgetController(TSubclassOf<UBreakerWidgetController> WidgetControllerClass, TObjectPtr<UBreakerWidgetController>& WidgetController, const FWidgetControllerParams& WCParams);

	void InitHUD(const FWidgetControllerParams& WCParams);

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UBreakerUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UBreakerWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UBreakerUserWidget> InteractionWidgetClass;

	UPROPERTY()
	TObjectPtr<UBreakerWidgetController> InteractionWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UInteractionWidgetController> InteractionWidgetControllerClass;
};
