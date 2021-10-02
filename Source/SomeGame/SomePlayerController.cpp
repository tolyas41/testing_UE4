// Fill out your copyright notice in the Description page of Project Settings.


#include "SomePlayerController.h"

void ASomePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &ASomePlayerController::MoveForward);

}

void ASomePlayerController::MoveForward(float Value)
{
	const FRotator Rotation = GetPawn()->Controller->GetControlRotation();
	const FRotator XRotation(Rotation.Pitch, 0, 0);

	const FVector Direction = FRotationMatrix(XRotation).GetUnitAxis(EAxis::X);
	GetPawn()->AddMovementInput(Direction, Value);

}