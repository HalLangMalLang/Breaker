// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Controller/BreakerPlayerController.h"
#include "UI/HUD/BreakerHUD.h"
#include "Player/Character/BreakerCharacter.h"
#include "Player/Component/PlayerStatComponent.h"
#include "UI/WidgetController/BreakerWidgetController.h"


void ABreakerPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (ABreakerHUD* BreakerHUD = Cast<ABreakerHUD>(GetHUD()))
	{
		if (ABreakerCharacter* BreakerCharacter = Cast<ABreakerCharacter>(GetPawn()))
		{
			FWidgetControllerParams WCParams(this, BreakerCharacter->PlayerStatComponent);

			BreakerHUD->InitHUD(WCParams);
		}
	}
}
