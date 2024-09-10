// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ClimbTopPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CLIMBTOP_API AClimbTopPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void SetPlayerEnabledState(bool bPlayerEnabled);

protected:
	virtual void SetupInputComponent() override;

private:
	void Restart();
};
