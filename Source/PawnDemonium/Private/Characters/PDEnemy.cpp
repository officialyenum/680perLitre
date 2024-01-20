// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PDEnemy.h"

#include "Characters/PDCharacter.h"
#include "Components/BoxComponent.h"
#include "Engine/DamageEvents.h"


APDEnemy::APDEnemy()
{
	// Set Attributes
	Hp = 100.f;
	MaxHp = 100;
	Gas = 100.f;
	MaxGas = 100.f;
	Attack = 10.f;
	bIsMoving = false;
	EnemyType = EChessPieceType::Knight;
	MoveRange = 200;
	
	FTimerHandle TimerHandleAIMove;
	// Call MoveBishop every 5 seconds
	// GetWorld()->GetTimerManager().SetTimer(TimerHandleAIMove, this, &APDEnemy::AIMove, 5.0f, true);
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

void APDEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Began"));
	if (OtherActor && OtherActor != this && OtherActor->IsA(APDCharacter::StaticClass()))
	{
		// Cast to your main character class and deal damage
		if (APDCharacter* PDCharacter = Cast<APDCharacter>(OtherActor))
		{
			// Implement damage logic on the main character
			PDCharacter->TakeDamage(Attack, FDamageEvent(), GetInstigatorController(), this);
			
			// Get the direction from the enemy to the character
			FVector PushDirection = OtherActor->GetActorLocation() - GetActorLocation();
			PushDirection.Normalize();
			// Apply a force to push the character away
			const float PushForce = Attack * 20.f;
			PDCharacter->LaunchCharacter(PushDirection * PushForce, true, true);
		}
	}
}



void APDEnemy::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap End"));
	
}

void APDEnemy::BishopMove()
{
}

void APDEnemy::RookMove()
{
}

void APDEnemy::KnightMove()
{
}

void APDEnemy::QueenMove()
{
}

void APDEnemy::KingMove()
{
}

void APDEnemy::AIMove()
{
	switch (EnemyType)
	{
	case EChessPieceType::Bishop:
		// Logic for Bishop
		//BishopMove();
		break;
	case EChessPieceType::Rook:
		// Logic for Rook
		//RookMove();
		break;
	case EChessPieceType::Knight:
		// Logic for Knight
		//KnightMove();
		break;
	case EChessPieceType::King:
		// Logic for King
		//KingMove();
		break;
	case EChessPieceType::Queen:
		// Logic for Queen
		//QueenMove();
		break;
	}
}

void APDEnemy::DealCharacterDamage(APDCharacter* otherActor, float DamageAmount)
{
	otherActor->CauseDamage(DamageAmount);
}

void APDEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Hp <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Died"));
		Destroy();
	}
}
