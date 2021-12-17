// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/WanderToPoint.h"
#include "ArcadeCompany/Public/Task/WanderPoints.h"
#include "ArcadeCompany/Public/Customers/Customer.h"
#include "ArcadeCompany/Public/Customers/CustomerController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UWanderToPoint::UWanderToPoint()
{
	wanderDistance = 500.0f;
}

EBTNodeResult::Type UWanderToPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	TArray<AActor*> wanderPoints;				// Reference array for wnader points
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWanderPoints::StaticClass(), wanderPoints);			// Get all the wander points

	// Ensure we have found wander points
	if(wanderPoints.Num() > 0)
	{
		
		int randIndex = FMath::RandRange(0, wanderPoints.Num() - 1);				// Select a random index from the wander points
		AActor* selectedWanderPoint = wanderPoints[randIndex];								// Select the wander points
		// Ensure we have selected the wander point
		if(selectedWanderPoint)
		{
			// Get the customer
			if(auto contr = Cast<ACustomerController>(OwnerComp.GetAIOwner()))
			{
				contr->SetMoveLocation(selectedWanderPoint->GetActorLocation());
				return EBTNodeResult::Succeeded;
			} else
			{
				if(GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("No Controller"));
			}
		} else
		{
			if(GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("No Selected Point"));
		}
	} else
	{
		if(GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, TEXT("No Points found"));
	}
	
	
	
	return EBTNodeResult::Failed;
}
