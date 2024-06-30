// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PGBlockerHandlerComponent.h"

UPGBlockerHandlerComponent::UPGBlockerHandlerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPGBlockerHandlerComponent::BeginPlay()
{
	Super::BeginPlay();	
}

void UPGBlockerHandlerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UPGBlockerHandlerComponent::IsBlocking(const EBlockers& Blocker) 
{
	TArray<UObject*> Keys;
	ActiveBlockers.GetKeys(Keys);

	for (UObject* key : Keys)
	{
		if (ActiveBlockers[key].Contains(Blocker))
		{
			return true;
		}
	}

	return false;
}

void UPGBlockerHandlerComponent::AddBlocker(UObject* BlockingObj, const TArray<EBlockers>& Blockers)
{
	ActiveBlockers.Add(BlockingObj, Blockers);
}

void UPGBlockerHandlerComponent::RemoveBlocker(UObject* BlockingObj)
{
	ActiveBlockers.Remove(BlockingObj);
}
