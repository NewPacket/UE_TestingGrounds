// Fill out your copyright notice in the Description page of Project Settings.

#include "BTChooseWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "TP_ThirdPerson/PatrollingGuard.h"

EBTNodeResult::Type UBTChooseWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto blackboardComp = OwnerComp.GetBlackboardComponent();
	auto index = blackboardComp->GetValueAsInt(selectedIndex.SelectedKeyName);
	auto owner = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	if (owner)
	{
		blackboardComp->SetValueAsObject(keySelector.SelectedKeyName, owner->patrolPoints[index]);
		auto nextIndex = (index + 1) % owner->patrolPoints.Num();
		blackboardComp->SetValueAsInt(selectedIndex.SelectedKeyName, nextIndex);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("cant find owner"))
	}
	return EBTNodeResult::Succeeded;
}


