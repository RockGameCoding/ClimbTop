// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class CLIMBTOP_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Variable
	UPROPERTY(EditAnywhere, Category="Moving")
	FVector MoveVelocity = FVector(100, 0, 0);
	UPROPERTY(EditAnywhere, Category="Moving")
	float MoveDistance = 100;
	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;
	FVector StartLocation;
	//Function
	void Move(float DeltaTime);
	void Rotation(float DeltaTime);
	bool ShouldReturn() const;
	float Distance() const;
};
