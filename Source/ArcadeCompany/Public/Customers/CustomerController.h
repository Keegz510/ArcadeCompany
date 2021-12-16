// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CustomerController.generated.h"
class UBehaviorTreeComponent;
class UBlackboardComponent;
class ACustomer;

/**
 * 
 */
UCLASS()
class ARCADECOMPANY_API ACustomerController : public AAIController
{
	GENERATED_BODY()
public:
	ACustomerController();
	/// Returns the blackboard component
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return bbComponent; }
	/// Returns the behaviour tree component
	FORCEINLINE UBehaviorTreeComponent* GetTreeComp() const { return btComponent; }
private:
	/// Reference to the behavior tree
	UBehaviorTreeComponent* btComponent;
	/// Reference to the blackboard component
	UBlackboardComponent* bbComponent;
	/// Reference to the customer
	ACustomer* customer;

#pragma region Blackboard Keys

	FName MoveToLoc;
	FName CustState;

#pragma endregion

	virtual void OnPossess(APawn* InPawn) override;
};
