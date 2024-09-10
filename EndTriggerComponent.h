// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GoalActor.h"
#include "EndTriggerComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CLIMBTOP_API UEndTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	UEndTriggerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	FName ActorTag;

	UPROPERTY(EditAnywhere, Category = "Goal")
	AGoalActor* Goal;

	AActor* IsActorTag() const;
};
