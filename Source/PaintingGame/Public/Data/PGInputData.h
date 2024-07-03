// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PGInputData.generated.h"

class UInputAction;

UCLASS()
class PAINTINGGAME_API UPGInputData : public UDataAsset
{
	GENERATED_BODY()

public:

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UInputAction* MoveForward;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UInputAction* MoveRight;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UInputAction* Interact;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UInputAction* LookUp;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UInputAction* Turn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* Jump;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    UInputAction* QuitGame;
};
