// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcadeCompany/Public/Controllers/BuildingController.h"
#include "ArcadeCompany/Public/Controllers/GameController.h"
#include "ArcadeCompany/Public/ArcadeMachine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABuildingController::ABuildingController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuildingController::BeginPlay()
{
	Super::BeginPlay();
	Controller = Cast<AGameController>(UGameplayStatics::GetActorOfClass(GetWorld(), AGameController::StaticClass()));
}


// Called every frame
void ABuildingController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(Controller != nullptr && !Controller->IsInBuildMode()) return;

	LineTraceToGround();	
}

void ABuildingController::SetPlacingMachine(FName machineName)
{
	// Loop through each object to find the specified object
	for(auto object :  placeableObjects)
	{
		// If the names match then set the placing object & break out of the loop
		if(object.ObjectName == machineName)
		{
			
			placingMachine = GetWorld()->SpawnActor<AArcadeMachine>(object.PlacingObject, FVector::ZeroVector, FRotator::ZeroRotator);
			break;
		}
	}
}

void ABuildingController::LineTraceToGround()
{
	// Ensure we have selected a machine before running any cast
	if(placingMachine == nullptr) return;

	// Get the player controller
	if(auto playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		FHitResult hit;				// Reference to the hit with raycast
		// Run the line trace
		playerController->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, true, hit);

		// Check the component we hit & see if it has the placeable tag
		if(UPrimitiveComponent* comp = hit.GetComponent())
		{
			if(comp->ComponentHasTag("Placeable"))
			{
				// Set the machine at that location
				const FVector location = hit.Location;
				placingMachine->SetActorLocation(location);
			}
		}
	}
	
	
}


