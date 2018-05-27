// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTChooseWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class PROOVINGGROUNDS_API UBTChooseWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector keySelector;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector selectedIndex;
};
