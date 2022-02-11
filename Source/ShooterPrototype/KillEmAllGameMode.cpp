// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"

#include "PlayerCharacter.h"
#include "ShooterPlayerController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);



	//check if Pawn killed is the player
	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if(PlayerController != nullptr)
	{
		
		PlayerController->GameHasEnded(nullptr, false);
	}
	
}
