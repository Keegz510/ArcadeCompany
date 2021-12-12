// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameController.generated.h"
class ACustomer;
UCLASS()
class ARCADECOMPANY_API AGameController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameController();

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
	
};
