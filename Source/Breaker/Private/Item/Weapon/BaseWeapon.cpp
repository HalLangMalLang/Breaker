// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/Weapon/BaseWeapon.h"
#include "Components/ArrowComponent.h"

ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	FirePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("FirePoint"));
	FirePoint->SetupAttachment(Mesh);

	AmmoPerFire = 1;
	CurrentAmmo = 0;
	MaxAmmo = 12;
	RoF = 1.f;
	bCanFire = true;
	Range = 1000.f;
	DamagePerHit = 10.f;
}

void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	CurrentAmmo = MaxAmmo;
}

void ABaseWeapon::Fire()
{
	bCanFire = false;
	GetWorldTimerManager().SetTimer(TimerFireDelay, this, &ABaseWeapon::HandleFireDelay, RoF, false);
}

void ABaseWeapon::HandleFireDelay()
{
	GetWorldTimerManager().ClearTimer(TimerFireDelay);
	bCanFire = true;
}