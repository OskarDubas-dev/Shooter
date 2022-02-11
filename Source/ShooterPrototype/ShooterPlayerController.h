// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERPROTOTYPE_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;
private:
	UPROPERTY(EditAnywhere)
	float RestartDelay = 4.0;

	FTimerHandle RestartTimer;
	
};