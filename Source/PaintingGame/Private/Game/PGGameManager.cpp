// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PGGameManager.h"
#include "Kismet/KismetMathLibrary.h"

APGGameManager::APGGameManager()
{
	PrimaryActorTick.bCanEverTick = false;
	MosaicSize = 5;
}

void APGGameManager::BeginPlay()
{
	Super::BeginPlay();	

	GenerateMosaic();
	StartGame();
}

void APGGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APGGameManager::GenerateMosaic() 
{
	int TrueSize = MosaicSize * MosaicSize;
	Mosaic.Empty();

	for (int i = 0; i < TrueSize; i++)
	{
		int randomColorId = UKismetMathLibrary::RandomInteger(AllowedColors.Num());
		Mosaic.Add(randomColorId);
	}
}

TArray<int32> APGGameManager::GetMosaic()
{
	return Mosaic;
}

int32 APGGameManager::GetMosaicSize()
{
	return MosaicSize;
}
