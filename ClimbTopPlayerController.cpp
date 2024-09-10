// Fill out your copyright notice in the Description page of Project Settings.


#include "ClimbTopPlayerController.h"
#include "Kismet/GameplayStatics.h"

void AClimbTopPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
    if(bPlayerEnabled)
    {
        GetPawn()->EnableInput(this);
    }
    else
    {
        GetPawn()->DisableInput(this);
    }
}

void AClimbTopPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    InputComponent->BindAction(TEXT("Restart"), IE_Released, this, &AClimbTopPlayerController::Restart);
}

void AClimbTopPlayerController::Restart()
{
    UGameplayStatics::OpenLevel(GetWorld(), FName(*GetWorld()->GetMapName()));
}