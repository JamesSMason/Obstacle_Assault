// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Making the platform move
		// Get current location
	FVector CurrentLocation = GetActorLocation();
		// Add a movement vector
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		// Set the new location
	SetActorLocation(CurrentLocation);
	// Send platform back if gone too far
		// Check how far platform has moved
	MoveDistance = FVector::Dist(StartLocation, CurrentLocation);
		// Reverse direction if gone too far
}

