// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/PDCharacterBase.h"
#include "Components/BoxComponent.h"
#include "PDEnemy.generated.h"

UENUM(BlueprintType)
enum class EChessPieceType : uint8
{
	Bishop UMETA(DisplayName = "Bishop"),
	Rook UMETA(DisplayName = "Rook"),
	Knight UMETA(DisplayName = "Knight"),
	King UMETA(DisplayName = "King"),
	Queen UMETA(DisplayName = "Queen")
};
/**
 * 
 */
UCLASS()
class PAWNDEMONIUM_API APDEnemy : public APDCharacterBase
{
	GENERATED_BODY()

public:
	APDEnemy();
	
	/** Collision Box to inflict Damage */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy Attributes", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* CollisionBox;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Attributes")
	EChessPieceType EnemyType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Attributes")
	bool bIsMoving;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Attributes")
	float MoveRange;
	

protected:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// To add mapping context
	virtual void BeginPlay() override;
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void AIMove();
	
	void BishopMove();
	
	void RookMove();
	
	void KnightMove();
	
	void QueenMove();
	
	void KingMove();
	
};
