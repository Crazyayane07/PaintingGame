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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "SetUp")
	float GameDuration;

	UFUNCTION(BlueprintPure, Category = "Mosaic")
	TArray<int32> GetMosaic();

	UFUNCTION(BlueprintPure, Category = "Mosaic")
	int32 GetMosaicSize();

	UFUNCTION(BlueprintPure, Category = "Game|Time")
	double GameTimeLeft();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void GenerateMosaic();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Game")
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent, Category = "Game")
	void EndGame();

	UPROPERTY(BlueprintReadOnly, Replicated, Category = "Game")
	TArray<int32> Mosaic;

	UPROPERTY(VisibleDefaultsOnly, Replicated, BlueprintReadWrite, Category = "Game|Time")
	double StartGameTime;

	void CheckGameTime();
};
