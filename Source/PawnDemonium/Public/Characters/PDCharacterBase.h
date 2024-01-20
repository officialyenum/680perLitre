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
	APDCharacterBase();

	UFUNCTION(BlueprintCallable, Category="Character Attributes")
	void CauseDamage(float DamageAmount);

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Attributes")
	float Hp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Attributes")
	float MaxHp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Attributes")
	float Gas;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Attributes")
	float MaxGas;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Attributes")
	float Attack;

};
