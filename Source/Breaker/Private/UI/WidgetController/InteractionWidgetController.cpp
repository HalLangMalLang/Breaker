#include "UI/WidgetController/InteractionWidgetController.h"
#include "Player/Character/BreakerCharacter.h"


void UInteractionWidgetController::Initialize()
{
	if (PlayerController)
	{
		ABreakerCharacter* BreakerCharacter = Cast<ABreakerCharacter>(PlayerController->GetPawn());

		if (IsValid(BreakerCharacter))
		{
			BreakerCharacter->OnTargetItemChanged.AddUObject(this, &UInteractionWidgetController::HandleTargetItemChanged);
			BreakerCharacter->OnItemAcquired.AddUObject(this, &UInteractionWidgetController::HandleItemAcquired);
			BreakerCharacter->OnInteractionProgressChanged.AddUObject(this, &UInteractionWidgetController::HandleInteractionProgressChanged);
		}
	}
}

void UInteractionWidgetController::HandleItemAcquired(const FString& ItemName)
{
	OnNotifyItemAcquired.Broadcast(ItemName);
}

void UInteractionWidgetController::HandleInteractionProgressChanged(float Percent)
{
	OnNotifyInteractionProgressChanged.Broadcast(Percent);
}

void UInteractionWidgetController::HandleTargetItemChanged(const FString& ItemName)
{
	OnNotifyTargetItemChanged.Broadcast(ItemName);
}