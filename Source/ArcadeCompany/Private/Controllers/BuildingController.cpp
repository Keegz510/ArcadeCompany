// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcadeCompany/Public/Controllers/BuildingController.h"
#include "ArcadeCompany/Public/Controllers/GameController.h"
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

void ABuildingController::LineTraceToGround()
{
	if(placingMachine == nullptr) return;
	
	if(auto playerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		FHitResult hit;
		playerController->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldDynamic, true, hit);

		if(UPrimitiveComponent* comp = hit.GetComponent())
		{
			if(comp->ComponentHasTag("Placeable"))
			{
				FVector location = hit.Location;
				placingMachine->SetActorLocation(location);
			}
		}
	}
	
	
}


