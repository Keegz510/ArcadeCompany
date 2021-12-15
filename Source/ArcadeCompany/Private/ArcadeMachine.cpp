// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcadeMachine.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AArcadeMachine::AArcadeMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	machineMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Machine Mesh"));
}

// Called when the game starts or when spawned
void AArcadeMachine::BeginPlay()
{
	Super::BeginPlay();
	
}

