// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcadeCompany/Public/Customers/Customer.h"

// Sets default values
ACustomer::ACustomer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SetSatisfactionDecreases();

	Tags.Add("Customer");

	currentState = ECustomerState::Deciding;
	bHasWaitedForTokens = false;
}

void ACustomer::SetCustomerState(const ECustomerState State)
{
	currentState = State;

	switch(currentState)
	{
		case ECustomerState::WaitingForTokens:
			IsWaitingForTokens();
			break;
	}
}

void ACustomer::IsWaitingForTokens()
{
	GetWorld()->GetTimerManager().SetTimer(
		waitingForTokensTimer, this, &ACustomer::WaitTimeSatisfactionDecrease, 5.0f, false);
}

// Called when the game starts or when spawned
void ACustomer::BeginPlay()
{
	Super::BeginPlay();
	int selectGender = FMath::RandRange(1, 100);
	if(selectGender > 50)
	{
		GetMesh()->SetSkeletalMesh(maleMesh);
	} else
	{
		GetMesh()->SetSkeletalMesh(femaleMesh);
	}
}

void ACustomer::DecreaseSatisfaction(const float value, bool isWaitingForTokens)
{
	currentSatisfaction -= value;

	if(isWaitingForTokens)
		bHasWaitedForTokens = true;
}

void ACustomer::SetSatisfactionDecreases()
{
	WaitTimeDecrease = FMath::RandRange(satisfactionValues.MinWaitTimeDecrease, satisfactionValues.MaxWaitTimeDecrease);
	WrongSnackDecrease = FMath::RandRange(satisfactionValues.minWrongSnackDecrease, satisfactionValues.maxWrongSnackDecrease);
}


