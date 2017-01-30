// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enum for firing status
UENUM()
enum class EFiringStatus: uint8
{
	Locked,
	Aiming,
	Reloading
};

//Forward declarations
class UTankBarrel;
class UTankTurret;
class ATankProjectile;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKPROJECT_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	//Enum instance for firing status
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Aiming;

	//Launch speed
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 100000.f; // Sensible start value of 1000 m/s

	// Projectile reference
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<ATankProjectile> ProjectileBlueprint;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	// Controls cadency of firing
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.f;
	double LastTimeFire = 0;
};