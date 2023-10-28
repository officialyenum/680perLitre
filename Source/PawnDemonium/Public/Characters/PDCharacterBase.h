// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PDCharacterBase.generated.h"

UCLASS(ABSTRACT)
class PAWNDEMONIUM_API APDCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = "attributes")
	float Hp = 0;

	UPROPERTY(BlueprintReadWrite, Category = "attributes")
	float Speed = 0;

	UPROPERTY(BlueprintReadWrite, Category = "attributes")
	float Attack = 0;
	// Sets default values for this character's properties
	APDCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "attributes")
	TObjectPtr<UStaticMeshComponent> PawnMesh;

};
