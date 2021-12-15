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


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	

private:
	void LineTraceToGround();


	class AGameController* Controller;

	class AArcadeMachine* placingMachine;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Placing Objects", meta=(AllowPrivateAccess="true"))
	TArray<FPlaceableObject> placeableObjects;

};
