// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGunBase;

UCLASS()
class THIRDPERSONSHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	float RotationRate = 10.f;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere)
	float Health;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGunBase> GunClass;

	UPROPERTY()
	AGunBase* Gun;

	void MoveForward(float AxisValue);
	void Strafe(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);
	void Shoot();
	void SetupPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintPure)
	bool IsPlayerDead() const;

	// Sets default values for this character's properties
	AShooterCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
};
