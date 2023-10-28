// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/PDCharacterBase.h"
#include "PDEnemy.generated.h"

/**
 * 
 */
UCLASS()
class PAWNDEMONIUM_API APDEnemy : public APDCharacterBase
{
	GENERATED_BODY()

public:
	APDEnemy();

protected:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// To add mapping context
	virtual void BeginPlay();
};
