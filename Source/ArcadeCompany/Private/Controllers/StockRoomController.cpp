// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/StockRoomController.h"

// Sets default values
AStockRoomController::AStockRoomController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStockRoomController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStockRoomController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

