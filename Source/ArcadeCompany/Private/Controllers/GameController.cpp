// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcadeCompany/Public/Controllers/GameController.h"
#include "ArcadeCompany/Public/Customers/Customer.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGameController::AGameController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

void AGameController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	LineTraceToCustomer();
	
}

void AGameController::GiveCustomerTokens()
{
	if(mouseOverCustomer != nullptr)
	{
		int32 tokens = mouseOverCustomer->GetRequestedTokens();
		mouseOverCustomer->AddTokens(tokens);
		storeCash += tokens;
		mouseOverCustomer = nullptr;
	}
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

void AGameController::LineTraceToCustomer()
{
	if(const auto pc = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		FHitResult hit;
		pc->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, false, hit);

		if(auto cust = Cast<ACustomer>(hit.GetActor()))
		{
			if(cust->GetCurrentState() == ECustomerState::WaitingForTokens)
			{
				mouseOverCustomer = cust;
			}
		}
	}
}
