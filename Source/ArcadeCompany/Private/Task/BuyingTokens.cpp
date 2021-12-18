// Fill out your copyright notice in the Description page of Project Settings.


#include "Task/BuyingTokens.h"

#include "Customers/Customer.h"
#include "Customers/CustomerController.h"

EBTNodeResult::Type UBuyingTokens::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	if(const auto controller = Cast<ACustomerController>(OwnerComp.GetAIOwner()))
	{
		controller->UpdateCustomerState(ECustomerState::WaitingForTokens);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
