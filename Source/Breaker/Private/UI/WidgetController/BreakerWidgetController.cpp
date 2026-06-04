// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/BreakerWidgetController.h"

void UBreakerWidgetController::SetWidgetController(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	StatComponent = WCParams.PlayerStatComponent;
}

void UBreakerWidgetController::Initialize(){}
