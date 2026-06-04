// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Weapon/BaseWeapon.h"
#include "BaseWeaponTemplate.generated.h"

/**
 * 
 */
UCLASS()
class BREAKER_API ABaseWeaponTemplate : public ABaseWeapon
{
	GENERATED_BODY()

public:
	virtual void Fire() override;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Reload();

	bool CanFire();
protected:
	UFUNCTION(BlueprintNativeEvent)
	bool CheckAmmo();

	// 총을 어떻게 쏠지
	UFUNCTION(BlueprintImplementableEvent)
	void ProcessFiring();

	// 이펙트 실행
	UFUNCTION(BlueprintImplementableEvent)
	void PlayEffects();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateAmmo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool showDebug = false;

	UFUNCTION(BlueprintCallable)
	void LinetraceOneShot(FVector Direction);

	UFUNCTION(BlueprintCallable)
	void LinetraceSpread(FVector Direction, int32 PellectCount, float SpreadAngle);

	UFUNCTION(BlueprintCallable)
	void ApplyRecoil();

};
