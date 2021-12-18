// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArcadeCompany/Public/ArcadeMachine.h"
#include "GameController.generated.h"
class ACustomer;
UCLASS()
class ARCADECOMPANY_API AGameController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameController();

	void ToggleBuildMode();
	UFUNCTION(BlueprintCallable)
	/// Returns if we are in build mode or not
	FORCEINLINE bool IsInBuildMode() const { return bIsBuildMode; }
	/// Adds a new machine to the world
	FORCEINLINE void AddArcadeMachine(AArcadeMachine* machine) { machinesInWorld.Add(machine);}

	/// Returns the amount of cash the player has
	FORCEINLINE int32 GetStoreCash() const { return storeCash; }
	/// Returns the amount of cash in a string
	UFUNCTION(BlueprintCallable)
	FString DisplayStoreCash();

	/// Handles taking cash away fromm the store (Generally when spending cash)
	FORCEINLINE void SpendCash(int32 amount) { storeCash -= amount; }
	/// Handles adding cash to the store
	FORCEINLINE void AddCash(int32 amount) { storeCash += amount; }

	void AddSatisfaction(float satisfaction);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character", meta=(AllowPrivateAcess="true"))
	class TSubclassOf<ACustomer> customer;
	
	

#pragma region Spawn Settings

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true", MakeEditWidget))
	FVector spawnLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	float MinSpawnWaitTime;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Spawning", meta=(AllowPrivateAccess="true"))
	float MaxSpawnWaitTime;

	FTimerHandle nextSpawnTimer;
	
	void SpawnCharacter();
	void StartSpawnTimer();

#pragma endregion

	bool bIsBuildMode = false;

	UFUNCTION(BlueprintImplementableEvent)
	void ToggleBuildingUI();

private:

	/// List of arcade machines placed in the world
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="In World Items", meta=(AllowPrivateAccess="true"))
	TArray<AArcadeMachine*> machinesInWorld;

	/// Reference to the amount of cash the store has
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Store Properties", meta=(AllowPrivateAccess="true"))
	int32 storeCash;

	/// How much cash the store starts with
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Store Properties|Settings", meta=(AllowPrivateAccess="true"))
	int32 startWithStoreCash;

	/// Reference to all the satisfaction ratings
	TArray<float> satisfactionRatings;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Satisfaction", meta=(AllowPrivateAccess="true"))
	float overallSatisfaction;

	
};
