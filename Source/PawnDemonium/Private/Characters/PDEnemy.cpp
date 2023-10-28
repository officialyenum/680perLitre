// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PDEnemy.h"


APDEnemy::APDEnemy()
{
	// Set Attributes
	Hp = 100.f;
	Attack = 10.f;
	Speed = 100.f;
}

void APDEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APDEnemy::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

}

void APDEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
