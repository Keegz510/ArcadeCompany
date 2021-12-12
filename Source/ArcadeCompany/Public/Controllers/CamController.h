// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Components", meta=(AllowPrivateAccess="true"))
	class USpringArmComponent* springArm;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Components", meta=(AllowPrivateAccess="true"))
	class UCameraComponent* camera;

	void MoveForward(const float value);
	void MoveRight(const float value);
};
