// Fill out your copyright notice in the Description page of Project Settings.


#include "NSS_GameMode.h"
#include "Food.h"

ANSS_GameMode::ANSS_GameMode() {
	PrimaryActorTick.bCanEverTick = true;
	spawnZ = 25.f;
	// FOOD
	foodSpawnMaxX = 2000.f;
	foodSpawnMaxY = 2000.f;
	foodSpawnMinX = -2000.f;
	foodSpawnMinY = -2000.f;

	// POP
	popSpawnMaxX = -2070.f;
	popSpawnMaxY = -1900.f;
	popSpawnMinX = -2070.f;
	popSpawnMinY = -2080.f;
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
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *SpawnPos.ToString());
	FRotator SpawnRot = FRotator(0.f, 0.f, 0.f);

	//FActorSpawnParameters SpawnParams;
	//SpawnParams.bNoFail = true;

	bool bNoCollisionFail = true;
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = bNoCollisionFail ? ESpawnActorCollisionHandlingMethod::AlwaysSpawn : ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	GetWorld()->SpawnActor(popToSpawn, &SpawnPos, &SpawnRot, ActorSpawnParams);
}

