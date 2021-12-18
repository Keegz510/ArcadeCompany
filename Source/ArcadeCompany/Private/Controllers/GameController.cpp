// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcadeCompany/Public/Controllers/GameController.h"
#include "ArcadeCompany/Public/Customers/Customer.h"

// Sets default values
AGameController::AGameController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AGameController::ToggleBuildMode()
{
	bIsBuildMode = !bIsBuildMode;
	ToggleBuildingUI();
}

FString AGameController::DisplayStoreCash()
{
	FString data = "$ ";
	FString amount = FString::FromInt(storeCash);
	data.Append(amount);
	return data;
}

void AGameController::AddSatisfaction(float satisfaction)
{
	
	satisfactionRatings.Add(satisfaction);			// Add the new satisfaction
	float total = 0.0f;				// Reference to the total of the satisfactions added together

	// Loop through each satisfaction and add them together
	for(auto rating : satisfactionRatings)
	{
		total += rating;
	}

	
	overallSatisfaction = total / satisfactionRatings.Num();			// Determine the average rating
	
}

// Called when the game starts or when spawned
void AGameController::BeginPlay()
{
	Super::BeginPlay();
	StartSpawnTimer();
	storeCash = startWithStoreCash;
}

void AGameController::SpawnCharacter()
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Purple, TEXT("Spawning Character"));
	}
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
