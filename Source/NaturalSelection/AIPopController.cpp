// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPopController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Pop.h"
#include "Food.h"
#include "Perception/AISenseConfig_Sight.h"

AAIPopController::AAIPopController() {
	PrimaryActorTick.bCanEverTick = true;
	AISightRadius = 500.f;
	AISightAge = 5.f;
	AILoseSightRadius = AISightRadius + 50.f;
	AIFieldOfView = 90.f;

	// UAISenseConfig_Sight* SightConfig = CreateOptionalDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	// SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	// SightConfig->SightRadius = AISightRadius;
	// SightConfig->LoseSightRadius = AILoseSightRadius;
	// SightConfig->PeripheralVisionAngleDegrees = AIFieldOfView;
	// SightConfig->SetMaxAge(AISightAge);

	// SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	// SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	// SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	// GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	// GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AAIPopController::OnPawnDetected);
	// GetPerceptionComponent()->ConfigureSense(*SightConfig);
}

void AAIPopController::BeginPlay()
{
	Super::BeginPlay();
	if (GetPerceptionComponent()) {
		UE_LOG(LogTemp, Warning, TEXT("All systems set!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Some problems occured!"));
	}
}

void AAIPopController::OnPossess(APawn* Paawn)
{
	Super::OnPossess(Paawn);
}

void AAIPopController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	// APop* pop = Cast<APop>(GetPawn());
	// if (pop->capturedFood && !pop->capturedFood->IsPendingKill()) {
	// 	UE_LOG(LogTemp, Warning, TEXT("Trying to move to food!"));
	// 	MoveToActor(pop->capturedFood, 0.f);
	// }
	// else {
	// 	pop->CaptureFood();
	// }
}

void AAIPopController::OnPawnDetected(const TArray<AActor*>& DetectedPawns)
{
}
