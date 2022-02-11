// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"

#include "Blueprint/UserWidget.h"

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	UE_LOG(LogTemp, Warning, TEXT("Game over"));
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	UUserWidget* GameOverScreen = CreateWidget(this, GameOverClass);
	if(GameOverScreen != nullptr)
	{
		GameOverScreen->AddToViewport();
	}
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
