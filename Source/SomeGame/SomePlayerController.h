// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SomePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SOMEGAME_API ASomePlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void SetupInputComponent() override;

	void MoveForward(float Value);
};
