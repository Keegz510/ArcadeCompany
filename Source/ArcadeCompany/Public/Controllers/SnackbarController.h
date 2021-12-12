// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnackbarController.generated.h"

USTRUCT(BlueprintType)
struct FSnack
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName SnackName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 SnackCost;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 SnackPrice;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 OnShelf;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 InStockRoom;
};

UCLASS()
class ARCADECOMPANY_API ASnackbarController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASnackbarController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Line Up", meta=(AllowPrivateAccess="true", MakeEditWidget))
	TArray<FVector> lineUpSpots;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Snacks", meta=(AllowPrivateAccess="true"))
	TArray<FSnack> snacks;
};
