// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/PDPlayerController.h"


APDPlayerController::APDPlayerController()
{
	bReplicates = true;
}

void APDPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}

void APDPlayerController::BeginPlay()
{
	Super::BeginPlay();
}


