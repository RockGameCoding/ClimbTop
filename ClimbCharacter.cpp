// Fill out your copyright notice in the Description page of Project Settings.


#include "ClimbCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AClimbCharacter::AClimbCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AClimbCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClimbCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AClimbCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Movement Binding
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AClimbCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AClimbCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AClimbCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AClimbCharacter::LookUp);
	//Action Binding
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Walk"), IE_Pressed, this, &AClimbCharacter::Walk);
	PlayerInputComponent->BindAction(TEXT("StopWalk"), IE_Released, this, &AClimbCharacter::StopWalk);
}

void AClimbCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AClimbCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AClimbCharacter::Turn(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AClimbCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AClimbCharacter::Walk()
{
	bIsWalk = true;
	if(bIsWalk)
	{
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
}

void AClimbCharacter::StopWalk()
{
	bIsWalk = false;
	if(!bIsWalk)
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
}