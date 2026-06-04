// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/BreakerHUD.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "UI/WidgetController/InteractionWidgetController.h"
#include "Player/Character/BreakerCharacter.h"
#include "Player/Component/PlayerStatComponent.h"
#include "UI/BreakerUserWidget.h"

UBreakerWidgetController* ABreakerHUD::GetWidgetController(TSubclassOf<UBreakerWidgetController> WidgetControllerClass, TObjectPtr<UBreakerWidgetController>& WidgetController, const FWidgetControllerParams& WCParams)
{
    if (!IsValid(WidgetController))
    {
        WidgetController = NewObject<UBreakerWidgetController>(this, WidgetControllerClass);

        WidgetController->SetWidgetController(WCParams);
    }

    return WidgetController;
}

void ABreakerHUD::InitHUD(const FWidgetControllerParams& WCParams)
{
    if (!OverlayWidgetClass) return;

    OverlayWidget = CreateWidget<UBreakerUserWidget>(GetWorld(), OverlayWidgetClass);
    if (OverlayWidget)
    {
        UOverlayWidgetController* WidgetController = Cast<UOverlayWidgetController>(GetWidgetController(OverlayWidgetControllerClass, OverlayWidgetController, WCParams));
        OverlayWidget->SetWidgetController(WidgetController);
        WidgetController->Initialize();

        OverlayWidget->AddToViewport();
    }

    InteractionWidget = CreateWidget<UBreakerUserWidget>(GetWorld(), InteractionWidgetClass);
    if (InteractionWidget)
    {
        UInteractionWidgetController* WidgetController = Cast<UInteractionWidgetController>(GetWidgetController(InteractionWidgetControllerClass, InteractionWidgetController, WCParams));
        InteractionWidget->SetWidgetController(WidgetController);
        WidgetController->Initialize();

        InteractionWidget->AddToViewport();
    }

}