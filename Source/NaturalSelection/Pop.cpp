// Fill out your copyright notice in the Description page of Project Settings.


#include "Pop.h"
#include "Food.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APop::APop()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	eatenFood = 0;

	speed = 1.f;
	size = 1.f;
	sence = 1.f;
	energy = 100.f;

	//Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	//SetRootComponent(Root);

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &APop::OnPlayerEnter);

	//SphereComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Sphere"));
	//SphereComponent->SetupAttachment(GetRootComponent());
	//SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &APop::OnPlayerEnter);
	//SphereComponent->InitCapsuleSize(50 * size, 150 * size);
	
}

// Called when the game starts or when spawned
void APop::BeginPlay()
{
	Super::BeginPlay();
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

void APop::OnPlayerEnter(UPrimitiveComponent* OverlapComponent,
							AActor* OtherActor,
							UPrimitiveComponent* OtherComponent,
							int32 OtherBodyIndex,
							bool bFromSweep,
							const FHitResult& SweepResult) {
		UE_LOG(LogTemp, Warning, TEXT("Collision hahhah!"));
		APop* Pop = nullptr;
		if (OtherActor) {
			Pop = Cast<APop>(OtherActor);
			if (Pop && (Pop->size / this->size >= 1.0f/0.7f)) {
				Destroy();
				Pop->Eat();
			}
		}
}