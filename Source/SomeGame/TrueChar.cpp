// Fill out your copyright notice in the Description page of Project Settings.


#include "TrueChar.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ATrueChar::ATrueChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));


    //SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    //SpringArm->SetupAttachment(RootComponent);
    //SpringArm->TargetArmLength = 400;

    //UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));

    //OurCamera->SetupAttachment(SpringArm);
    //OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
    //OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

}

// Called when the game starts or when spawned
void ATrueChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrueChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATrueChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATrueChar::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATrueChar::MoveRight);

}

void ATrueChar::MoveForward(float Value)
{
    if ((Controller) && (Value != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        //const FVector Direction = FRotationMatrix(SpringArm->GetDesiredRotation()).GetScaledAxis(EAxis::X);
        AddMovementInput(Direction, Value);

        UE_LOG(LogTemp, Warning, TEXT("DFFDFD, %f"), Value);
        FString SomeS = Direction.ToString();
        UE_LOG(LogTemp, Warning, TEXT("%s"), *SomeS);

    }
}

void ATrueChar::MoveRight(float Value)
{
    if ((Controller) && (Value != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        //const FVector Direction = FRotationMatrix(SpringArm->GetDesiredRotation()).GetScaledAxis(EAxis::X);
        AddMovementInput(Direction, Value);

        UE_LOG(LogTemp, Warning, TEXT("DFFDFD, %f"), Value);
        FString SomeS = Direction.ToString();
        UE_LOG(LogTemp, Warning, TEXT("%s"), *SomeS);

    }
}
