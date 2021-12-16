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
