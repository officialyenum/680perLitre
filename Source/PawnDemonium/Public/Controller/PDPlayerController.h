// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PDPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PAWNDEMONIUM_API APDPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	APDPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
};
