// Fill out your copyright notice in the Description page of Project Settings.


#include "ArcadeCompany/Public/UI/MainHUD.h"
#include "Kismet/GameplayStatics.h"
#include "ArcadeCompany/Public/Controllers/GameController.h"

void UMainHUD::ToggleBuildMode()
{
	if(AGameController* gm = Cast<AGameController>(
		UGameplayStatics::GetActorOfClass(GetWorld(), AGameController::StaticClass())))
	{
		gm->ToggleBuildMode();
	}
}
