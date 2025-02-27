// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PGPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/TextRenderComponent.h" 
#include "EnhancedInputSubsystems.h"
#include "Data/PGInputData.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/PGBlockerHandlerComponent.h"

APGPlayer::APGPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	HeadSocket = FName("Head");	

	SpingArmComp  = CreateDefaultSubobject<USpringArmComponent>("SpingArmComp");
	SpingArmComp->SetupAttachment(RootComponent);
	SpingArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpingArmComp);

	TextRenderComp = CreateDefaultSubobject<UTextRenderComponent>("TextRenderComp");
	TextRenderComp->SetupAttachment(RootComponent);

	BlockerHandlerComp = CreateDefaultSubobject<UPGBlockerHandlerComponent>("BlockerHandlerComp");
}

void APGPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	if (APlayerController* PC = Cast<APlayerController>(GetController())) 
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
		    Subsystem->ClearAllMappings();
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
	}
}

void APGPlayer::LookUp(const FInputActionValue& Value)
{
	if (IsBlocking(EBlockers::MOVEMENT)) 
	{
		return;
	}

	const float MoveValue = Value.Get<float>() * -1.f;
	AddControllerPitchInput(MoveValue);
}

void APGPlayer::Turn(const FInputActionValue& Value)
{
	if (IsBlocking(EBlockers::MOVEMENT)) 
	{
		return;
	}

	const float MoveValue = Value.Get<float>();
	AddControllerYawInput(MoveValue);
}

void APGPlayer::MoveForward(const FInputActionValue& Value)
{
	if (IsBlocking(EBlockers::MOVEMENT)) 
	{
		return;
	}

	const float TurnValue = Value.Get<float>();
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	AddMovementInput(ControlRot.Vector(), TurnValue);
}

void APGPlayer::MoveRight(const FInputActionValue& Value)
{
	if (IsBlocking(EBlockers::MOVEMENT)) 
	{
		return;
	}

	const float TurnValue = Value.Get<float>();
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;
	
	FVector Directon = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);

	AddMovementInput(Directon, TurnValue);
}

void APGPlayer::TriggerJump()
{
	if (IsBlocking(EBlockers::MOVEMENT)) 
	{
		return;
	}

	Jump();
}

void APGPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APGPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (!InputData)
	{
		return;
	}

	if (UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent)) 
	{
		PEI->BindAction(InputData->MoveForward, ETriggerEvent::Triggered, this, &APGPlayer::MoveForward);
		PEI->BindAction(InputData->LookUp, ETriggerEvent::Triggered, this, &APGPlayer::LookUp);
		PEI->BindAction(InputData->Turn, ETriggerEvent::Triggered, this, &APGPlayer::Turn);
		PEI->BindAction(InputData->MoveRight, ETriggerEvent::Triggered, this, &APGPlayer::MoveRight);
		PEI->BindAction(InputData->Jump, ETriggerEvent::Started, this, &APGPlayer::TriggerJump);
		PEI->BindAction(InputData->Interact, ETriggerEvent::Started, this, &APGPlayer::TryInteract);
		PEI->BindAction(InputData->QuitGame, ETriggerEvent::Started, this, &APGPlayer::QuitGame);
	}

}

bool APGPlayer::IsBlocking(const EBlockers& Blocker)
{
	return BlockerHandlerComp->IsBlocking(Blocker);
}

