// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PGBlockerHandlerComponent.generated.h"

UENUM(BlueprintType)
enum class EBlockers : uint8 
{
	MOVEMENT,
	INTERACTION
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PAINTINGGAME_API UPGBlockerHandlerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UPGBlockerHandlerComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure, Category = "Blocker")
	bool IsBlocking(const EBlockers& Blocker);

	UFUNCTION(BlueprintCallable, Category = "Blocker")
	void AddBlocker(UObject* BlockingObj, const TArray<EBlockers>& Blockers);

	UFUNCTION(BlueprintCallable, Category = "Blocker")
	void RemoveBlocker(UObject* BlockingObj);

protected:

	virtual void BeginPlay() override;
		
	TMap<UObject*, TArray<EBlockers>> ActiveBlockers;
};
