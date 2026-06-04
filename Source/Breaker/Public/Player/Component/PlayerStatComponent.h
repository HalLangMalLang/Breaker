// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Types\BreakerPlayerTypes.h"
#include "PlayerStatComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnHPChangedDelegate, float, float, float);
DECLARE_MULTICAST_DELEGATE(FOnDeathDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BREAKER_API UPlayerStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPlayerStatComponent();

protected:

	virtual void BeginPlay() override;
public:
	// 새로운 스탯 데이터로 초기화
	void SetStats(const FPlayerStatData& NewStats);

	//체력을 치유
	UFUNCTION(BlueprintCallable, Category = "Player|Stat")
	void HealHP(float Amount);

	// 데미지를 적용
	UFUNCTION(BlueprintCallable, Category = "Player|Stat")
	void ApplyDamage(float Amount);


	// 플레이어의 기본 스탯 데이터 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player|Stat")
	FPlayerStatData PlayerStats;

	// 체력이 변경될 때마다 호출되는 델리게이트
	FOnHPChangedDelegate OnHPChanged;

	// 사망했을 때 호출되는 델리게이트
	FOnDeathDelegate OnDeath;
};
