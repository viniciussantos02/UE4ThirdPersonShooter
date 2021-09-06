// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GunBase.generated.h"

UCLASS()
class THIRDPERSONSHOOTER_API AGunBase : public AActor
{
	GENERATED_BODY()
	
private:
	FVector ViewPointLocation;
	FRotator ViewPointRotation;
	APawn* OwnerPawn;
	AController* OwnerController;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	float MaxLineRange = 1000;

	UPROPERTY(EditAnywhere)
	float Damage = 20;

	UPROPERTY(EditDefaultsOnly, Category = "Particles")
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere, Category = "Particles")
	UParticleSystem* MuzzleFlash;
	
	FVector GetLineTraceEnd();
	void ApplyDamage(const FHitResult& Hit, const FVector& ShotDirection);
	void SetupGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AGunBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PullTrigger();
};
