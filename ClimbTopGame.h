// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ClimbTopGame.generated.h"

/**
 * 
 */
UCLASS()
class CLIMBTOP_API AClimbTopGame : public AGameModeBase
{
	GENERATED_BODY()

public:
	AClimbTopGame();

	void GameEnd();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> MyHUDClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> GameEndClass;

	float RestartDelay = 3.f;

	FTimerHandle RestartTimer;

	void HandleGameStart();

	class AClimbTopPlayerController* PlayerController;

	float StartDelay = 4.f;

	void RestartLevel();
};
