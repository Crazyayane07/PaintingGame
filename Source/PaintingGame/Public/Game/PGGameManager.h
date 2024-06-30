// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PGGameManager.generated.h"

UCLASS()
class PAINTINGGAME_API APGGameManager : public AActor
{
	GENERATED_BODY()
	
public:	

	APGGameManager();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly,  Category = "SetUp")
	TArray<FLinearColor> AllowedColors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SetUp")
	int32 MosaicSize;

	UFUNCTION(BlueprintPure, Category = "Mosaic")
	TArray<int32> GetMosaic();

	UFUNCTION(BlueprintPure, Category = "Mosaic")
	int32 GetMosaicSize();

protected:

	virtual void BeginPlay() override;

	void GenerateMosaic();

	UFUNCTION(BlueprintImplementableEvent, Category = "Game")
	void StartGame();

	TArray<int32> Mosaic;

};
