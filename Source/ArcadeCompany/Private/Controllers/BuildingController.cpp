// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcadeCompany/Public/Controllers/BuildingController.h"

// Sets default values
ABuildingController::ABuildingController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuildingController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuildingController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

