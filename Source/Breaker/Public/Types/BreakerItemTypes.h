// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BreakerItemTypes.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Weapon		UMETA(DisplayName = "Weapon"),
	Consumable	UMETA(DisplayName = "Consumable"),
	Ammo		UMETA(DisplayName = "Ammo")
};

UENUM(BlueprintType)
enum class EItemSlotType : uint8
{
	MainWeapon		UMETA(DisplayName = "Main Weapon"),
	SubWeapon		UMETA(DisplayName = "Sub Weapon"),
	Potion			UMETA(DisplayName = "Consumable"),
	Inventory		UMETA(DisplayName = "Inventory")
};