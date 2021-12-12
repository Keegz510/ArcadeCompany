// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcadeCompany/Public/Controllers/GameController.h"
#include "ArcadeCompany/Public/Customers/Customer.h"

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
	StartSpawnTimer();
}

void AGameController::SpawnCharacter()
{

	UE_LOG(LogTemp, Warning, TEXT("May Spawn Character"));
	// Generate a random value to help determine if someone is coming into the store
	int randValue = FMath::RandRange(1, 100);
	
	if(randValue > 50)
		GetWorld()->SpawnActor<ACustomer>(customer, spawnLocation, FRotator::ZeroRotator);

	StartSpawnTimer();
	
}

void AGameController::StartSpawnTimer()
{
	float randTime = FMath::RandRange(MinSpawnWaitTime, MaxSpawnWaitTime);
	GetWorld()->GetTimerManager().SetTimer(
		nextSpawnTimer, this, &AGameController::SpawnCharacter, randTime, false);
}
