// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcadeCompany/Public/Controllers/GameController.h"

// Sets default values
AGameController::AGameController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AGameController::BeginPlay()
{
	Super::BeginPlay();
	
}
