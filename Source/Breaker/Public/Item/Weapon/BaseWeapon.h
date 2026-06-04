// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Types/BreakerPlayerTypes.h"
#include "Item/ItemBase.h"
#include "BaseWeapon.generated.h"

class UNiagaraSystem;

UCLASS()
class BREAKER_API ABaseWeapon : public AItemBase
{
	GENERATED_BODY()
	
public:
	ABaseWeapon();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<class UArrowComponent> FirePoint;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCameraShakeBase> CameraShakeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform EquipOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform HolsterOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponType")
	EWeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Montage")
	FCharacterAnimMontages CharacterAnimMontages;

	UFUNCTION(BlueprintCallable)
	virtual void Fire();

protected:
	virtual void BeginPlay() override;
	// 소모되는 탄약수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AmmoPerFire;

	// 남은 탄약수
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly)
	int32 CurrentAmmo;

	// 탄약 보유량
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxAmmo;

	// 연사속도
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RoF;

	// 유효사거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Range;

	// 데미지양
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamagePerHit;

	// 쏠수있나
	UPROPERTY(BlueprintReadWrite)
	bool bCanFire;

	//연사속도 제어를 위한 핸들
	UPROPERTY(BlueprintReadWrite)
	FTimerHandle TimerFireDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
	UNiagaraSystem* MuzzleEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
	UNiagaraSystem* ImpactEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float PitchRecoilMin = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float PitchRecoilMax = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float YawRecoilMin = -0.1f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float YawRecoilMax = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	float ViewStartOffset = 175.f;

	UFUNCTION()
	void HandleFireDelay();

};
