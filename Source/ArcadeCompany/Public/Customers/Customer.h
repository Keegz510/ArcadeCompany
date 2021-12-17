// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Customer.generated.h"

class USkeletalMesh;
class UBehaviorTree;

USTRUCT(BlueprintType)
struct FSatisfactionValues
{
	GENERATED_BODY()
public:
	/// Min Decrease in satisfaction if Waiting for a snack or a machine
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MinWaitTimeDecrease;
	/// Min Decrease in satisfaction if provived the wrong snack
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxWaitTimeDecrease;

	/// Min Decrease in satisfaction if provived the wrong snack
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float minWrongSnackDecrease;
	/// Min Decrease in satisfaction if provived the wrong snack
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float maxWrongSnackDecrease;
};

UENUM(BlueprintType)
enum ECustomerState
{
	Deciding,
	WantsSnack,
	OrderSnack,
	PlayingMachine,
	MoveToMachine,
	FindMachine
};

UCLASS()
class ARCADECOMPANY_API ACustomer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACustomer();

	/// Returns the reference to the behaviour tree
	FORCEINLINE UBehaviorTree* GetBT() const { return behaviorTree; }
	/// Returns how many tokens the customer has
	FORCEINLINE int32 GetTokensAmount() const { return tokens; }
	/// Sets the current state of the customer
	FORCEINLINE void SetCustomerState(const ECustomerState State) { currentState = State; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/// Reference to the character male mesh
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Meshes", meta=(AllowPrivateAccess="true"))
	USkeletalMesh* maleMesh;
	/// Reference to the character female Mesh
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Meshes", meta=(AllowPrivateAccess="true"))
	USkeletalMesh* femaleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Satisfaction", meta=(AllowPrivateAccess="true"))
	FSatisfactionValues satisfactionValues;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Satisfaction", meta=(AllowPrivateAccess="true"))
	float WaitTimeDecrease;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Satisfaction", meta=(AllowPrivateAccess="true"))
	float WrongSnackDecrease;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Satisfaction", meta=(AllowPrivateAccess="true"))
	float currentSatisfaction = 50.0f;

	/// Reference to the behaviour tree
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AI|Components", meta=(AllowPrivateAccess="true"))
	UBehaviorTree* behaviorTree;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AI|States", meta=(AllowPrivateAccess="true"))
	TEnumAsByte<ECustomerState> currentState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Play Settings", meta=(AllowPrivateAccess="true"))
	int32 tokens;

	void SetSatisfactionDecreases();
};
