// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuildingController.generated.h"

UCLASS()
class ARCADECOMPANY_API ABuildingController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingController();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetPlacingMachine(AActor* machine);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	

private:
	void LineTraceToGround();


	class AGameController* Controller;

	AActor* placingMachine;

};
