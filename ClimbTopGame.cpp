// Fill out your copyright notice in the Description page of Project Settings.


#include "ClimbTopGame.h"
#include "Blueprint/UserWidget.h"
#include "TimerManager.h"
#include "ClimbTopPlayerController.h"
#include "Kismet/GameplayStatics.h"

AClimbTopGame::AClimbTopGame()
{
    PlayerControllerClass = AClimbTopPlayerController::StaticClass();
}

void AClimbTopGame::BeginPlay()
{
    Super::BeginPlay();
    UUserWidget* HUD = CreateWidget(GetWorld(), MyHUDClass);
    if(HUD != nullptr)
    {
        HUD->AddToViewport();
    }
    HandleGameStart();
}

void AClimbTopGame::GameEnd()
{
    UUserWidget* GameEndWidget = CreateWidget(GetWorld(), GameEndClass);
    if(GameEndWidget != nullptr)
    {
        GameEndWidget->AddToViewport();
    }
    GetWorldTimerManager().SetTimer(RestartTimer, this, &AClimbTopGame::RestartLevel, RestartDelay);
}

void AClimbTopGame::HandleGameStart()
{
    PlayerController = Cast<AClimbTopPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
    if(PlayerController)
    {
        PlayerController->SetPlayerEnabledState(false);
        //Set Timer(StartDelay)
        FTimerHandle PlayerEnableTimerHandle;
        FTimerDelegate PlayerEnableTimerDelagate = FTimerDelegate::CreateUObject(
            PlayerController, 
            &AClimbTopPlayerController::SetPlayerEnabledState, 
            true);
        GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, PlayerEnableTimerDelagate, StartDelay, false);
    }
}

void AClimbTopGame::RestartLevel()
{
    UGameplayStatics::OpenLevel(GetWorld(), FName(*GetWorld()->GetMapName()));
}