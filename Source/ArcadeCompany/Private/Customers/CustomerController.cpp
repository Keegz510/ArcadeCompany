// Fill out your copyright notice in the Description page of Project Settings.


#include "Customers/CustomerController.h"
#include "ArcadeCompany/Public/Customers/Customer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"

ACustomerController::ACustomerController()
{
	btComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BT Component"));
	bbComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BB Component"));

	MoveToLoc = FName(TEXT("MoveToLocation"));
	CustState = FName(TEXT("CustomerState"));
}

void ACustomerController::SetMoveLocation(const FVector location) const
{
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Setting move to location"));
	bbComponent->SetValueAsVector(MoveToLoc, location);
}

void ACustomerController::UpdateCustomerState(const ECustomerState newState)
{
	bbComponent->SetValueAsEnum(CustState, newState);
	customer->SetCustomerState(newState);
}

void ACustomerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	customer = Cast<ACustomer>(InPawn);

	if(customer)
	{
		if(customer->GetBT()->BlackboardAsset)
		{
			bbComponent->InitializeBlackboard(*(customer->GetBT()->BlackboardAsset));
		}
		btComponent->StartTree(*customer->GetBT());
	}
}
