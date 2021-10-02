// Fill out your copyright notice in the Description page of Project Settings.


#include "Pers.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "SomePlayerController.h"
#include "Components/CapsuleComponent.h"


APers::APers()
{
    PrimaryActorTick.bCanEverTick = true;
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    //CollisionCylinder = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionCylinderTrue"));
    //CollisionCylinder->SetupAttachment(RootComponent);

    StaticMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(RootComponent);

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(StaticMesh);
    SpringArm->TargetArmLength = 400;

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));

    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    //OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
    //OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));



}

// Called every frame
void APers::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    if (!CurrentVelocity.IsZero())
    {
        FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
        SetActorLocation(NewLocation);
    }
    
}

// Called to bind functionality to input
void APers::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &APers::MoveForward);
    PlayerInputComponent->BindAction("TapForward", IE_Pressed, this, &APers::TapForward);
}


void APers::MoveForward(float Value)
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

void APers::TapForward()
{
    FVector NewLocation = GetActorLocation() + 10;
    SetActorLocation(NewLocation);
}