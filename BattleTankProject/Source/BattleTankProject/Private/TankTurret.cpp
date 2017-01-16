// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Log the situation
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto RotationAmount = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationAmount;

	SetRelativeRotation(FRotator(0, Rotation, 0)); // Set rotation
}


