// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/LeftArcade.h"

#include "Controllers/GameController.h"
#include "Customers/CustomerController.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type ULeftArcade::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	// Get the customer controller of the customer leaving
	const auto controller = Cast<ACustomerController>(OwnerComp.GetAIOwner());
	// Get the game controller
	const auto GC = Cast<AGameController>(UGameplayStatics::GetActorOfClass(GetWorld(), AGameController::StaticClass()));

	// Ensure both the controllers are valid
	if(controller && GC)
	{
		// Get the reference to the customer & ensure it's valid
		auto customer = Cast<ACustomer>(controller->GetOwner());
		if(customer)
		{
			GC->AddSatisfaction(customer->GetSatisfaction());				// Add satisfaction
			customer->Destroy(true, true);			// Destroy the actor
			return EBTNodeResult::Succeeded;
		}
	}
	
	return EBTNodeResult::Failed;
}
