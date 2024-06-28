// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PGPlayer.generated.h"

class UCameraComponent;
class UTextRenderComponent;

UCLASS()
class PAINTINGGAME_API APGPlayer : public ACharacter
{
	GENERATED_BODY()

public:

	APGPlayer();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UTextRenderComponent* TextRenderComp;

	UPROPERTY(EditDefaultsOnly, Category = "SetOp")
	FName HeadSocket;

};
