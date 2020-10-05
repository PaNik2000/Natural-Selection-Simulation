// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "Pop.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SetRootComponent(Root);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger Sphere"));
	SphereComponent->SetupAttachment(GetRootComponent());
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AFood::OnPlayerEnter);

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFood::OnPlayerEnter(UPrimitiveComponent* OverlapComponent,
						  AActor* OtherActor,
						  UPrimitiveComponent* OtherComponent,
						  int32 OtherBodyIndex,
						  bool bFromSweep,
						  const FHitResult& SweepResult){
	UE_LOG(LogTemp, Warning, TEXT("Collision!"));
	APop* Pop = nullptr;
	if (OtherActor) {
		Pop = Cast<APop>(OtherActor);
		if (Pop) {
			Destroy();
			Pop->Eat();
			Pop->CaptureFood();
		}
	}
}

