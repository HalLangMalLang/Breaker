// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Weapon/BaseWeaponTemplate.h"
#include "NiagaraFunctionLibrary.h"
#include "Components/ArrowComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Player\Character\BreakerCharacter.h"

void ABaseWeaponTemplate::Fire()
{
	if (!bCanFire)
	{
		return;
	}

	if (CheckAmmo())
	{
		PlayEffects();
		ProcessFiring();
		ApplyRecoil();
		UpdateAmmo();
		if (ABreakerCharacter* BreakerCharacter = Cast<ABreakerCharacter>(GetOwner()))
		{
			BreakerCharacter->PlayAnimMontage(CharacterAnimMontages.Fire);

			if (APlayerController* PC = Cast<APlayerController>(BreakerCharacter->GetController()))
			{
				if (PC->PlayerCameraManager)
				{
					PC->PlayerCameraManager->StartCameraShake(CameraShakeClass, 1.0f);
				}
			}
		}

		if (MuzzleEffect)
		{
			UNiagaraFunctionLibrary::SpawnSystemAttached(MuzzleEffect, Mesh, FName(TEXT("Socket_Muzzle")), FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::KeepRelativeOffset, true);
		}
		Super::Fire();
	}
}

bool ABaseWeaponTemplate::CanFire()
{
	if (bCanFire && CheckAmmo())
	{
		return true;
	}

	return false;
}


bool ABaseWeaponTemplate::CheckAmmo_Implementation()
{
	return AmmoPerFire <= CurrentAmmo;
}

void ABaseWeaponTemplate::Reload_Implementation()
{
	CurrentAmmo = MaxAmmo;
}

void ABaseWeaponTemplate::UpdateAmmo_Implementation()
{
	CurrentAmmo -= AmmoPerFire;
}

void ABaseWeaponTemplate::LinetraceOneShot(FVector Direction)
{
	FVector ViewPointLocation;
	FRotator ViewPointRotation;

	// 카메라의 현재 위치와 회전값 가져오기
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);

	// ViewStartOffset 만큼 시작 지점을 앞으로 전진
	ViewPointLocation = ViewPointLocation + ViewPointRotation.Vector() * ViewStartOffset;

	// 시작 지점으로부터 발사 거리(Range)만큼 최종 도달 지점 계산
	FVector End = ViewPointLocation + ViewPointRotation.Vector() * Range;

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	bool bHit = GetWorld()->LineTraceSingleByChannel
	(
		HitResult,
		ViewPointLocation,
		End,
		ECC_Visibility,
		Params
	);

	if (showDebug)
	{
		// 판정용 트레이스 : 디버그 출력
		DrawDebugLine(
			GetWorld(),
			ViewPointLocation,
			End,
			FColor::Red,
			false,
			5.f,
			0,
			2.0f
		);


		FVector MuzzleLocation = FirePoint->GetComponentLocation();
		FVector VisualTraceEnd;

		if (bHit)
		{
			VisualTraceEnd = HitResult.ImpactPoint;
		}
		else
		{
			VisualTraceEnd = HitResult.TraceEnd;
		}

		// 연출용 트레이스 : 디버그 출력
		DrawDebugLine
		(
			GetWorld(),
			MuzzleLocation,
			VisualTraceEnd,
			FColor::Blue,
			false,
			5.f,
			0,
			2.0f
		);
	}

	// 라인트레이스에 히트시 태그로 대미지 처리
	if (HitResult.GetActor())
	{
		AActor* HitActor = HitResult.GetActor();

		if (HitActor->ActorHasTag(FName(TEXT("Enemy"))))
		{
			UGameplayStatics::ApplyDamage(HitActor, DamagePerHit, nullptr, this, UDamageType::StaticClass());
			UE_LOG(LogTemp, Log, TEXT("%s : %f 피해"), *HitResult.GetActor()->GetActorLabel(), DamagePerHit);
		}

		if (ImpactEffect)
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactEffect, HitResult.ImpactPoint, HitResult.ImpactNormal.Rotation());
		}

	}
}

void ABaseWeaponTemplate::LinetraceSpread(FVector Direction, int32 PellectCount, float SpreadAngle)
{
	for (int32 i = 0; i < PellectCount; i++)
	{
		FVector ViewPointLocation;
		FRotator ViewPointRotation;
		// 카메라의 현재 위치와 회전값 가져오기
		GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(ViewPointLocation, ViewPointRotation);

		// ViewStartOffset 만큼 시작 지점을 앞으로 전진
		ViewPointLocation = ViewPointLocation + ViewPointRotation.Vector() * ViewStartOffset;

		// 탄 퍼짐(Bullet Spread) 방향(원뿔 모양의 가상 공간(Cone) 안에서 무작위 방향 벡터(VRandCone)를 추출)
		FVector SpreadDir = FMath::VRandCone(ViewPointRotation.Vector(), FMath::DegreesToRadians(SpreadAngle));

		// 시작 지점으로부터 발사 거리(Range)만큼 최종 도달 지점 계산
		FVector End = ViewPointLocation + SpreadDir * Range;

		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);

		bool bHit = GetWorld()->LineTraceSingleByChannel
		(
			HitResult,
			ViewPointLocation,
			End,
			ECC_Visibility,
			Params
		);


		if (showDebug)
		{
			// 판정용 트레이스 : 디버그 출력
			DrawDebugLine
			(
				GetWorld(),
				ViewPointLocation,
				End,
				FColor::Red,
				false,
				5.f,
				0,
				2.0f
			);

			FVector MuzzleLocation = FirePoint->GetComponentLocation();
			FVector VisualTraceEnd;

			if (bHit)
			{
				VisualTraceEnd = HitResult.ImpactPoint;
			}
			else
			{
				VisualTraceEnd = HitResult.TraceEnd;
			}

			// 연출용 트레이스 : 디버그 출력
			DrawDebugLine
			(
				GetWorld(),
				MuzzleLocation,
				VisualTraceEnd,
				FColor::Blue,
				false,
				5.f,
				0,
				2.0f
			);
		}

		if (HitResult.GetActor())
		{
			AActor* HitActor = HitResult.GetActor();

			if (HitActor->ActorHasTag(FName(TEXT("Enemy"))))
			{
				UGameplayStatics::ApplyDamage(HitActor, DamagePerHit, nullptr, this, UDamageType::StaticClass());
				UE_LOG(LogTemp, Log, TEXT("%s : %f 피해"), *HitResult.GetActor()->GetActorLabel(), DamagePerHit);
			}

			if (ImpactEffect)
			{
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ImpactEffect, HitResult.ImpactPoint, HitResult.ImpactNormal.Rotation());
			}
		}
	}
}

void ABaseWeaponTemplate::ApplyRecoil()
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (PC)
	{
		float YawRecoil = FMath::FRandRange(YawRecoilMin, YawRecoilMax);
		float PitchRecoil = FMath::FRandRange(PitchRecoilMin, PitchRecoilMax);

		PC->AddPitchInput(-PitchRecoil);
		PC->AddYawInput(YawRecoil);
	}
}
