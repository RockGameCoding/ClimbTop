// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
	Rotation(DeltaTime);
}

void AObstacle::Move(float DeltaTime)
{
	if(ShouldReturn())
	{
		FVector MoveDirection = MoveVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		MoveVelocity = -MoveVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + MoveVelocity * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

void AObstacle::Rotation(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AObstacle::ShouldReturn() const
{
	return Distance() > MoveDistance;
}

float AObstacle::Distance() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}