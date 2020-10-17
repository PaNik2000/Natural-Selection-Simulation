// Fill out your copyright notice in the Description page of Project Settings.


#include "NSS_GameMode.h"
#include "Food.h"

ANSS_GameMode::ANSS_GameMode() {
	PrimaryActorTick.bCanEverTick = true;
	spawnZ = 25.f;
	// FOOD
	foodSpawnMaxX = 2560.f;
	foodSpawnMaxY = 2560.f;
	foodSpawnMinX = -2560.f;
	foodSpawnMinY = -2560.f;

	// POP
	popSpawnMaxX = -2560.f;
	popSpawnMaxY = 2760.f;
	popSpawnMinX = -2760.f;
	popSpawnMinY = -2760.f;
}

void ANSS_GameMode::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < popAmount; ++i) {
		SpawnPop();
	}
	for (int i = 0; i < foodAmount; ++i) {
		SpawnFood();
	}
}

void ANSS_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANSS_GameMode::SpawnFood()
{
	float RandX = FMath::RandRange(foodSpawnMinX, foodSpawnMaxX);
	float RandY = FMath::RandRange(foodSpawnMinY, foodSpawnMaxY);

	FVector SpawnPos = FVector(RandX, RandY, spawnZ);
	FRotator SpawnRot = FRotator(0.f, 0.f, 0.f);

	GetWorld()->SpawnActor(foodToSpawn, &SpawnPos, &SpawnRot);
}

void ANSS_GameMode::SpawnPop() 
{
	float RandX = FMath::RandRange(popSpawnMinX, popSpawnMaxX);
	float RandY = FMath::RandRange(popSpawnMinY, popSpawnMaxY);

	FVector SpawnPos = FVector(RandX, RandY, spawnZ);
	FRotator SpawnRot = FRotator(0.f, 0.f, 0.f);

	GetWorld()->SpawnActor(popToSpawn, &SpawnPos, &SpawnRot);
}

