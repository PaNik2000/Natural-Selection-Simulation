// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "NSS_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class NATURALSELECTION_API ANSS_GameMode : public AGameMode
{
	GENERATED_BODY()

	ANSS_GameMode();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> actorToSpawn;

	UPROPERTY(EditAnywhere)
	int foodAmount;

	float spawnZ;

	UPROPERTY(EditAnywhere)
		float spawnMaxX;
	UPROPERTY(EditAnywhere)
		float spawnMinX;
	UPROPERTY(EditAnywhere)
		float spawnMaxY;
	UPROPERTY(EditAnywhere)
		float spawnMinY;

	void SpawnFood();
};
