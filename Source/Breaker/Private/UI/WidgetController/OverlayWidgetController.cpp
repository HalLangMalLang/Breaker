// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "Player/Component/PlayerStatComponent.h"

void UOverlayWidgetController::Initialize()
{
	UPlayerStatComponent* PlayerStatComponent = Cast<UPlayerStatComponent>(StatComponent);
	if (IsValid(PlayerStatComponent))
	{
		PlayerStatComponent->OnHPChanged.AddUObject(this, &UOverlayWidgetController::HandleHpChanged);

		OnNotifyHpChanged.Broadcast(PlayerStatComponent->PlayerStats.CurrentHP, PlayerStatComponent->PlayerStats.MaxHP, 0.f);
	}
}

void UOverlayWidgetController::HandleHpChanged(float CurrentHP, float MaxHP, float HealthDelta)
{
	OnNotifyHpChanged.Broadcast(CurrentHP, MaxHP, HealthDelta);
}

