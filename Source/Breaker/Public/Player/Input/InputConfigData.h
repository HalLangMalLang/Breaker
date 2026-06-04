// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputConfigData.generated.h"

class UInputAction;

UCLASS()
class BREAKER_API UInputConfigData : public UDataAsset
{
	GENERATED_BODY()

public:
	// 점프
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;

	// 이동
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MoveAction;

	// 마우스 회전
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

	// 달리기
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* SprintAction;

	// 조준
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* AimAction;

	// 공격
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* FireAction;

	// 주무기 장착/배치
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* PrimaryAction;

	// 보조무기 장착/배치
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* SecondaryAction;

	// 주무기 드랍
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* PrimaryDropAction;

	// 보조무기 드랍
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* SecondaryDropAction;

	// 손전등
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* TorchAction;

	// 상호작용
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* InteractAction;
};
