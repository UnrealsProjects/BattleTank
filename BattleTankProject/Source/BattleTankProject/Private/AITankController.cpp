// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "AITankController.h"


ATank* AAITankController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

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
		// TODO Move towards player

		ControlledTank->AimAt(PlayerTank->GetActorLocation()); // Get player location

		// AI fire at player
		ControlledTank->Fire();
	}

}

ATank * AAITankController::GetPlayerTank() const
{
	auto* PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

