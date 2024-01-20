// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PDCharacterBase.h"

// Sets default values
APDCharacterBase::APDCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void APDCharacterBase::CauseDamage(float DamageAmount)
{
	Hp -= FMath::Min(Hp, DamageAmount);
}

// Called when the game starts or when spawned
void APDCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

