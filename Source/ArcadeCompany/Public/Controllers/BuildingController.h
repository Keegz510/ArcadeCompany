// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuildingController.generated.h"

USTRUCT(BlueprintType)
struct FPlaceableObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ObjectName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<class AArcadeMachine> PlacingObject;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 machineCost;
};

UCLASS()
class ARCADECOMPANY_API ABuildingController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingController();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetPlacingMachine(FName machineName);

	/// Cancels the placement of the current object
	UFUNCTION(BlueprintCallable)
	void CancelPlacement();
	/// Rotates the current placing object
	UFUNCTION(BlueprintCallable)
	void RotatePlacingObject();
	/// Places the object in the world
	UFUNCTION(BlueprintCallable)
	void PlaceObjectInWorld();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	

private:
	void LineTraceToGround();
	/// Reference to the game controller
	class AGameController* Controller;

	/// The object we are currently placing in the world
	class AArcadeMachine* placingMachine;
	
	/// Reference to all the objects that we can place in the world
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Placing Objects", meta=(AllowPrivateAccess="true"))
	TArray<FPlaceableObject> placeableObjects;

	

};
