// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Types/BreakerItemTypes.h"
#include "ItemBase.generated.h"

UCLASS()
class BREAKER_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UTexture2D* ItemIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	UTexture2D* HoverIcon;

	UFUNCTION(BlueprintCallable)
	virtual void Interact(ACharacter* Character);

	UFUNCTION(BlueprintCallable)
	virtual void Use(ACharacter* Character);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	EItemSlotType SlotType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stack")
	bool bIsStackable = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stack")
	int32 MaxStackSize = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Stack")
	int32 Quantity = 1;
};
