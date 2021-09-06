// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ThirdPersonShooter/Actors/GunBase.h"
#include "Rifle.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONSHOOTER_API ARifle : public AGunBase
{
	GENERATED_BODY()
	
private:
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	ARifle();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PullTrigger() override;
};
