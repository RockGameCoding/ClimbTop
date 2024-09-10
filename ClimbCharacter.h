// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ClimbCharacter.generated.h"

UCLASS()
class CLIMBTOP_API AClimbCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AClimbCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//Movement
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void Turn(float AxisValue);
	void LookUp(float AxisValue);
	//Action
	void Walk();
	void StopWalk();
	
	//Movement Variable
	UPROPERTY(EditAnywhere, Category="Movement")
	float RotationRate = 10.f;
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	float SprintSpeed = 600.0f;
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	float WalkSpeed = 200.0f;
	bool bIsWalk = false;
};
