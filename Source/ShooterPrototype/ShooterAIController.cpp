// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"

#include "PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

bool AShooterAIController::IsDead() const
{
	APlayerCharacter* ControlledCharacter = Cast<APlayerCharacter>(GetPawn());
	if(ControlledCharacter != nullptr)
	{
		return ControlledCharacter->IsDead();
	}
	return true;
}

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (AIBehaviorTree != nullptr)
	{
		RunBehaviorTree(AIBehaviorTree);
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
	}
}

void AShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
