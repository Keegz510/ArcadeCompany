// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/Leaving.h"

#include "Controllers/GameController.h"
#include "Kismet/GameplayStatics.h"
#include "ArcadeCompany/Public/Customers/CustomerController.h"
#include "ArcadeCompany/Public/Customers/Customer.h"

EBTNodeResult::Type ULeaving::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	AGameController* GC = Cast<AGameController>(UGameplayStatics::GetActorOfClass(GetWorld(), AGameController::StaticClass()));

	if(GC)
	{
		const FVector location = GC->GetSpawnLocation();
		if(const auto controller = Cast<ACustomerController>(OwnerComp.GetAIOwner()))
		{
			controller->SetMoveLocation(location);
		}
	}
	
	return EBTNodeResult::Failed;
}
