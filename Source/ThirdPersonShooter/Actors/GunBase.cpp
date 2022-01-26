// Fill out your copyright notice in the Description page of Project Settings.


#include "GunBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGunBase::AGunBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AGunBase::BeginPlay()
{
	Super::BeginPlay();		
	
}

// Called every frame
void AGunBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGunBase::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));

	if (GetGunOwnerController() != nullptr)
	{
		FVector LineTraceEnd = GetLineTraceEnd();				

		FCollisionQueryParams Params;
		Params.AddIgnoredActor(this);
		Params.AddIgnoredActor(GetOwner());	

		FHitResult Hit;

		bool bSucces = GetWorld()->LineTraceSingleByChannel(
			OUT Hit,
			ViewPointLocation,
			LineTraceEnd,
			ECollisionChannel::ECC_GameTraceChannel1,
			Params
		);			

		if (bSucces)
		{
			FVector ShotDirection = -ViewPointRotation.Vector();

			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation());

			ApplyDamage(Hit, ShotDirection);
		}
	}
}

FVector AGunBase::GetLineTraceEnd()
{
	GetGunOwnerController()->GetPlayerViewPoint(OUT ViewPointLocation, OUT ViewPointRotation);

	return ViewPointLocation + ViewPointRotation.Vector() * MaxLineRange;
}

void AGunBase::ApplyDamage(const FHitResult& Hit, const FVector& ShotDirection)
{
	AActor* HitActor = Hit.GetActor();

	if (HitActor != nullptr)
	{
		FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);

		HitActor->TakeDamage(Damage, DamageEvent, GetGunOwnerController(), this);
	}
}

AController* AGunBase::GetGunOwnerController()
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());

	if (OwnerPawn)
	{
		OwnerController = OwnerPawn->GetController();
	}

	return OwnerController;
}
