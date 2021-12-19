// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/MakeDecision.h"

#include "Customers/CustomerController.h"
#include "Customers/Customer.h"

EBTNodeResult::Type UMakeDecision::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	if(auto controller = Cast<ACustomerController>(OwnerComp.GetAIOwner()))
	{
		if(auto customer = Cast<ACustomer>(controller->GetOwningCustomer()))
		{
			const int32 tokens = customer->GetTokensAmount();
			if(tokens == 0)
			{
				const int32 randValue = FMath::RandRange(1, 100);
				if(randValue > 70)
				{
					controller->UpdateCustomerState(ECustomerState::Leaving);
				} else
				{
					controller->UpdateCustomerState(ECustomerState::BuyingTokens);
				}
			} else
			{
				int randValue = FMath::RandRange(1, 100);
				if(randValue < 50)
				{
					controller->UpdateCustomerState(ECustomerState::FindMachine);
				} else if (randValue > 50 && randValue < 75)
				{
					controller->UpdateCustomerState(ECustomerState::WantsSnack);
				} else
				{
					controller->UpdateCustomerState(ECustomerState::Leaving);
				}
			}
		}
	}


	return EBTNodeResult::Failed;
}
