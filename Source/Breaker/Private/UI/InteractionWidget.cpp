// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InteractionWidget.h"
#include "Player\Character\BreakerCharacter.h"
#include "Components\TextBlock.h"

void UInteractionWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (GuideText)
	{
		GuideText->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (AcquisitionText)
	{
		AcquisitionText->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UInteractionWidget::ShowGuide(const FString& ItemName)
{
	if (GuideText)
	{
		GuideText->SetText(FText::FromString(FString::Printf(TEXT("[E] %s"), *ItemName)));
		GuideText->SetVisibility(ESlateVisibility::Visible);
	}
}

void UInteractionWidget::HideGuide()
{
	if (GuideText)
	{
		GuideText->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UInteractionWidget::ShowAcquisitionMessage(const FString& ItemName)
{
	if (AcquisitionText)
	{

		AcquisitionText->SetText(FText::FromString(ItemName));
		AcquisitionText->SetVisibility(ESlateVisibility::Visible);


		GetWorld()->GetTimerManager().ClearTimer(AcquisitionTimerHandle);

		GetWorld()->GetTimerManager().SetTimer(
			AcquisitionTimerHandle,
			this,
			&UInteractionWidget::HideAcquisitionMessage,
			ItemDisplayDuration,
			false
		);
	}
}

void UInteractionWidget::HandleTargetItemChanged(const FString& ItemName)
{
	if (ItemName.IsEmpty())
	{
		HideGuide();
	}
	else
	{
		ShowGuide(ItemName);
	}
}

void UInteractionWidget::HideAcquisitionMessage()
{
	if (AcquisitionText)
	{
		AcquisitionText->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UInteractionWidget::OnInteractionProgressUpdated(float Percent)
{
	UpdateCircularGauge(Percent);
}
