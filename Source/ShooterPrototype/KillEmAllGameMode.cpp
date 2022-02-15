// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"

#include "EngineUtils.h"
#include "PlayerCharacter.h"
#include "ShooterAIController.h"
#include "ShooterPlayerController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);

	
	//check if Pawn killed is the player
	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController != nullptr)
	{
		EndGame(false);
	}else
	{
		EnemyCounter--;

		if(EnemyCounter <= 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("Number of enemies: %i"), EnemyCounter);
			EndGame(true);
		}
	}

	


	
	
}

void AKillEmAllGameMode::BeginPlay()
{
	Super::BeginPlay();

	//loop through all the enemy ai and count them
	for(AShooterAIController* AIController : TActorRange<AShooterAIController>(GetWorld()))
	{
		EnemyCounter++;
	}

	UE_LOG(LogTemp, Warning, TEXT("Number of enemies: %i"), EnemyCounter);
	
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}
