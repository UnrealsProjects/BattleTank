// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TankProjectile.generated.h"

//Forward declaration
class UProjectileMovementComponent;

UCLASS()
class BATTLETANKPROJECT_API ATankProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATankProjectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Method that handle projectile movement
	void LaunchProjectile(float Speed);

private:
	UProjectileMovementComponent* ProjectileMC = nullptr;
};
