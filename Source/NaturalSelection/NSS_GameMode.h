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
	TSubclassOf<AActor> foodToSpawn;
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> popToSpawn;

	UPROPERTY(EditAnywhere)
	int foodAmount;
	UPROPERTY(EditAnywhere)
	int popAmount;

	float spawnZ;

	UPROPERTY(EditAnywhere)
	float foodSpawnMaxX; 
	UPROPERTY(EditAnywhere)
	float foodSpawnMinX;
	UPROPERTY(EditAnywhere)
	float foodSpawnMaxY;
	UPROPERTY(EditAnywhere)
	float foodSpawnMinY;

	UPROPERTY(EditAnywhere)
	float popSpawnMaxX; 
	UPROPERTY(EditAnywhere)
	float popSpawnMinX;
	UPROPERTY(EditAnywhere)
	float popSpawnMaxY;
	UPROPERTY(EditAnywhere)
	float popSpawnMinY;


	void SpawnFood();
	void SpawnPop();
};
