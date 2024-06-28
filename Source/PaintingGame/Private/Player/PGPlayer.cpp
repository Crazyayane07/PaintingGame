// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PGPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/TextRenderComponent.h" 

APGPlayer::APGPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	HeadSocket = FName("Head");

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(GetMesh(), HeadSocket);

	TextRenderComp = CreateDefaultSubobject<UTextRenderComponent>("TextRenderComp");
	TextRenderComp->SetupAttachment(GetMesh(), HeadSocket);
}

void APGPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void APGPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APGPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

