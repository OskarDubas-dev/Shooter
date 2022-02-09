// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_Shoot.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERPROTOTYPE_API UBTTask_Shoot : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTask_Shoot();
	APlayerCharacter* AIPawn;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
