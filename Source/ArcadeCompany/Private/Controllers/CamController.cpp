// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcadeCompany/Public/Controllers/CamController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
// Sets default values
ACamController::ACamController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	springArm->TargetArmLength = 1000.0f;
	springArm->SetupAttachment(RootComponent);
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(springArm, USpringArmComponent::SocketName);
}

// Called when the game starts or when spawned
void ACamController::BeginPlay()
{
	Super::BeginPlay();
	currentCameraZoom = maxCameraZoom / 1.25f;
	springArm->TargetArmLength = currentCameraZoom;
}

// Called to bind functionality to input
void ACamController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Movements
	PlayerInputComponent->BindAxis("MoveForward", this, &ACamController::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACamController::MoveRight);
	PlayerInputComponent->BindAxis("Rotate", this, &ACharacter::AddControllerYawInput);

	// Camera Zoom
	PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &ACamController::ZoomIn);
	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &ACamController::ZoomOut);
}

void ACamController::MoveForward(const float value)
{
	if(Controller && value != 0)
	{
		const FRotator rotation = Controller->GetControlRotation();
		const FVector direction = FRotationMatrix(rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(direction, value);
	}
}

void ACamController::MoveRight(const float value)
{
	if(Controller && value != 0)
	{
		const FRotator rotation = Controller->GetControlRotation();
		const FVector direction = FRotationMatrix(rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(direction, value);
	}
}

void ACamController::ZoomIn()
{
	if(springArm && currentCameraZoom > minCameraZoom)
	{
		currentCameraZoom -= (1 * cameraZoomSpeed);
		springArm->TargetArmLength = currentCameraZoom;
	}
}

void ACamController::ZoomOut()
{
	if(springArm && currentCameraZoom < maxCameraZoom)
	{
		currentCameraZoom += (1 * cameraZoomSpeed);
		springArm->TargetArmLength = currentCameraZoom;
	}
}



