// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/MoveToTokenBar.h"

#include "Customers/Customer.h"
#include "Customers/CustomerController.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UMoveToTokenBar::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	ACustomerController* controller = Cast<ACustomerController>(OwnerComp.GetAIOwner());

	if(controller)
	{
		TArray<AActor*> tempActors;
		UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(TEXT("TokenBuyPoint")), tempActors);
		const AActor* buyPoint = tempActors[0];

		if(buyPoint)
		{
			const FVector location = buyPoint->GetActorLocation();
			controller->SetMoveLocation(location);
			return EBTNodeResult::Succeeded;
		}
		
	}
	
	return EBTNodeResult::Failed;
}
