// Fill out your copyright notice in the Description page of Project Settings.


#include "EndTriggerComponent.h"

UEndTriggerComponent::UEndTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UEndTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UEndTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor* Actor = IsActorTag();
    if(Actor != nullptr && Goal != nullptr)
    {
        Goal->EndGame();
    }
}

AActor* UEndTriggerComponent::IsActorTag() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    for(AActor* Actor : Actors)
    {
        if(Actor->ActorHasTag(ActorTag))
        {
            return Actor;
        }
    }
    return nullptr;
}