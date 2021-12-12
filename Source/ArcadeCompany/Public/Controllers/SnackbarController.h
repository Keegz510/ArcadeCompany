// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnackbarController.generated.h"

UCLASS()
class ARCADECOMPANY_API ASnackbarController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnackbarController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:

};
