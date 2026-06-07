// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/BreakerGameMode.h"
#include "Subsystem/ObjectPool/ObjectPoolSubsystem.h"

void ABreakerGameMode::BeginPlay()
{
	if (UObjectPoolSubsystem* PoolSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UObjectPoolSubsystem>())
	{
		if (!PooledObjectData.IsEmpty())
		{
			PoolSubsystem->SetupPools(PooledObjectData);
		}
	}
}
