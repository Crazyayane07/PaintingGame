// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/PGGameManager.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

APGGameManager::APGGameManager()
{
	PrimaryActorTick.bCanEverTick = true;
	MosaicSize = 5;
	GameDuration = 20.0;

	SetActorTickEnabled(false);
	bReplicates = true;
}

void APGGameManager::BeginPlay()
{
	Super::BeginPlay();	
}

void APGGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckGameTime();
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

void APGGameManager::CheckGameTime()
{
	double CurrentTime = UGameplayStatics::GetTimeSeconds(GetWorld());

	if (CurrentTime - StartGameTime > GameDuration) 
	{
		EndGame();
	}
}

double APGGameManager::GameTimeLeft()
{
	return GameDuration - (UGameplayStatics::GetTimeSeconds(GetWorld()) - StartGameTime);
}

TArray<int32> APGGameManager::GetMosaic()
{
	return Mosaic;
}

int32 APGGameManager::GetMosaicSize()
{
	return MosaicSize;
}

void APGGameManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APGGameManager, Mosaic);
}
