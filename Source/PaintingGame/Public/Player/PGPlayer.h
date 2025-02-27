// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "PGPlayer.generated.h"

class UCameraComponent;
class UTextRenderComponent;
class UPGInputData;
class UInputMappingContext;
class USpringArmComponent;
class UPGBlockerHandlerComponent;

UCLASS()
class PAINTINGGAME_API APGPlayer : public ACharacter
{
	GENERATED_BODY()

public:

	APGPlayer();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure, category = "Blockers")
	bool IsBlocking(const EBlockers& Blocker);

protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UPGBlockerHandlerComponent* BlockerHandlerComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UTextRenderComponent* TextRenderComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpingArmComp;

	UPROPERTY(EditDefaultsOnly, Category = "SetUp")
	FName HeadSocket;

	UPROPERTY(EditDefaultsOnly, Category = "SetUp|Input")
	UPGInputData* InputData;

	UPROPERTY(EditDefaultsOnly, Category = "SetUp|Input")
	UInputMappingContext* InputMappingContext;

	void LookUp(const FInputActionValue& Value);

	void Turn(const FInputActionValue& Value);

	void MoveForward(const FInputActionValue& Value);

	void MoveRight(const FInputActionValue& Value);

	UFUNCTION(BlueprintImplementableEvent, category = "Interaction")
	void TryInteract();

	UFUNCTION(BlueprintImplementableEvent, category = "Game")
	void QuitGame();

	void TriggerJump();

};
