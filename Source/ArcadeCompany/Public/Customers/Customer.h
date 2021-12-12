// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Customer.generated.h"

class USkeletalMesh;

UCLASS()
class ARCADECOMPANY_API ACustomer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACustomer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/// Reference to the character male mesh
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Meshes", meta=(AllowPrivateAccess="true"))
	USkeletalMesh* maleMesh;
	/// Reference to the character female Mesh
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Meshes", meta=(AllowPrivateAccess="true"))
	USkeletalMesh* femaleMesh; 
	
};
