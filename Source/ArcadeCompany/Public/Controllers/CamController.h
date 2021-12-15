// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "CamController.generated.h"

UCLASS()
class ARCADECOMPANY_API ACamController : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACamController();
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE FVector GetCameraPosition() const { return camera->GetComponentLocation();}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	/// Reference to the spring arm component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components", meta=(AllowPrivateAccess="true"))
	class USpringArmComponent* springArm;
	/// Reference to the camera Component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	class UCameraComponent* camera;

	/// Min amount that the camera can zoom in
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zoom Settings", meta=(AllowPrivateAccess="true"))
	float minCameraZoom;
	/// Max amount that the camera can zoom in
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zoom Settings", meta=(AllowPrivateAccess="true"))
	float maxCameraZoom;
	/// Reference to the current zoom the camera is at
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Zoom Settings", meta=(AllowPrivateAccess="true"))
	float currentCameraZoom;
	/// How fast the camera will zoom in at
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Zoom Settings", meta=(AllowPrivateAccess="true"))
	float cameraZoomSpeed = 1.0f;
	/// Handles moving backwards & forwards
	void MoveForward(const float value);
	/// Handles moving left & right
	void MoveRight(const float value);

	/// Handles the user input for cancelling building placement
	void CancelBuilding();

	/// Handles the camera zoom in
	void ZoomIn();
	/// Handles the camera zoom out
	void ZoomOut();
};
