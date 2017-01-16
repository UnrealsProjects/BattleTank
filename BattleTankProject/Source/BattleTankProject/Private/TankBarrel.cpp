// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Log the situation
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationAmount = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawRotation = RelativeRotation.Pitch + ElevationAmount;

	auto Elevation = FMath::Clamp<float>(RawRotation, MinDegreeElevation, MaxDegreeElevation);

	SetRelativeRotation(FRotator(Elevation, 0, 0)); // Set rotation
}

