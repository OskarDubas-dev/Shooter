// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShooterPrototypeGameModeBase.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERPROTOTYPE_API AKillEmAllGameMode : public AShooterPrototypeGameModeBase
{
	GENERATED_BODY()
public:
	virtual void PawnKilled(APawn* PawnKilled) override;
	virtual void BeginPlay() override;
private:
	void EndGame(bool bIsPlayerWinner);

	int EnemyCounter;
	
};
