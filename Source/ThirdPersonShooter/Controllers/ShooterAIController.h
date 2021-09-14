// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

class AShooterCharacter;

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

private:
	UPROPERTY()
	AShooterCharacter* PlayerPawn;

	UPROPERTY(EditAnywhere)
	float AIDistanceFromPlayer = 200.f;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
