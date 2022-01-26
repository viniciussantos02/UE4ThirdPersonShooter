// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"
#include "AIController.h"
#include "ThirdPersonShooter/Characters/ShooterCharacter.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (!OwnerComp.GetAIOwner()) return EBTNodeResult::Failed;

	if (!OwnerComp.GetAIOwner()->GetPawn()) return EBTNodeResult::Failed;

	Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn())->Shoot();

	return EBTNodeResult::Succeeded;
}