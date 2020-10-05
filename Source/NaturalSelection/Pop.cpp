// Fill out your copyright notice in the Description page of Project Settings.


#include "Pop.h"
#include "Food.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APop::APop()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	capturedFood = nullptr;
	eatenFood = 0;
}

// Called when the game starts or when spawned
void APop::BeginPlay()
{
	Super::BeginPlay();

	CaptureFood();
}

void APop::CaptureFood()
{
	TArray<AActor*> FoundActors;
	TArray<AFood*> FoundFood;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFood::StaticClass(), FoundActors);
	for (AActor* TActor : FoundActors)
	{
		AFood* fFood = Cast<AFood>(TActor);

		if (fFood != nullptr)
			FoundFood.Add(fFood);
	}

	if (FoundFood.Num() <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Didn't find any food"));
		capturedFood = nullptr;
		return;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Found some food %d"), FoundFood.Num());
		float currentClosestDistance = TNumericLimits<float>::Max();
		for (int i = 0; i < FoundFood.Num(); i++)
		{
			float distance = FVector::DistSquared(this->GetActorLocation(), FoundFood[i]->GetActorLocation());
			if (distance < currentClosestDistance)
			{
				currentClosestDistance = distance;
				capturedFood = FoundFood[i];
			}
		}
	}
}

// Called every frame
void APop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APop::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

