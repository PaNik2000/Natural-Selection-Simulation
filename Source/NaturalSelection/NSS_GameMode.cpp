// Fill out your copyright notice in the Description page of Project Settings.


#include "NSS_GameMode.h"
#include "Food.h"

ANSS_GameMode::ANSS_GameMode() {
	PrimaryActorTick.bCanEverTick = true;
	spawnZ = 25.f;
	spawnMaxX = 2760.f;
	spawnMaxY = 2760.f;
	spawnMinX = -2760.f;
	spawnMinY = -2760.f;
}

void ANSS_GameMode::BeginPlay()
{
	Super::BeginPlay();
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
	float RandX = FMath::RandRange(spawnMinX, spawnMaxX);
	float RandY = FMath::RandRange(spawnMinY, spawnMaxY);

	FVector SpawnPos = FVector(RandX, RandY, spawnZ);
	FRotator SpawnRot = FRotator(0.f, 0.f, 0.f);

	GetWorld()->SpawnActor(actorToSpawn, &SpawnPos, &SpawnRot);
}
