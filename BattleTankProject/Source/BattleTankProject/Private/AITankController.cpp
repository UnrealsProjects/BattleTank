// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "AITankController.h"

void AAITankController::BeginPlay()
{
	Super::BeginPlay();
}

void AAITankController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

		ControlledTank->AimAt(PlayerTank->GetActorLocation()); // Get player location

		// AI fire at player
		ControlledTank->Fire();
	}

}

