// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Pop.generated.h"

UCLASS()
class NATURALSELECTION_API APop : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APop();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int eatenFood;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float size;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float sence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float energy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	inline void Eat() { eatenFood++; };

	
};
