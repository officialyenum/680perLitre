// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PDEnemy.h"

#include "Characters/PDCharacter.h"
#include "Components/BoxComponent.h"
#include "Engine/DamageEvents.h"


APDEnemy::APDEnemy()
{
	// Set Attributes
	Hp = 100.f;
	Attack = 10.f;
	Speed = 100.f;
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

void APDEnemy::AIMove()
{
	switch (EnemyType)
	{
	case EChessPieceType::Bishop:
		// Logic for Bishop
		BishopMove();
		break;
	case EChessPieceType::Rook:
		// Logic for Rook
		RookMove();
		break;
	case EChessPieceType::Knight:
		// Logic for Knight
		KnightMove();
		break;
	case EChessPieceType::King:
		// Logic for King
		KingMove();
		break;
	case EChessPieceType::Queen:
		// Logic for Queen
		QueenMove();
		break;
	}
}

void APDEnemy::BishopMove()
{
	// Simulate the Rooks's move (200 units Up Left, UP Right, Down Right, or Down Left)
	const int32 Direction = FMath::RandRange(0,3); // 8 moves
	float XDirection = 0;
	float YDirection = 0;
	switch (Direction)
	{
	case 0:
		// Move Up Left
		XDirection += MoveRange;
		YDirection -= MoveRange;
		break;
	case 1:
		// Move Up Right
		XDirection += MoveRange;
		YDirection += MoveRange;
		break;
	case 2:
		// Move Down Left
		XDirection -= MoveRange;
		YDirection -= MoveRange;
		break;
	default:
		// Move Down Right
		XDirection -= MoveRange;
		YDirection += MoveRange;
		break;
	}
	const FVector StartLocation = GetActorLocation();
	const FVector EndLocation = StartLocation + FVector(XDirection, YDirection, 0.f); // Move 200 units up
	const float Duration = 1.0f;
	const float ElapsedTime = 5.0f;

	// Interpolate for the upward movement
	const FVector NewLocationUp = FMath::Lerp(StartLocation, EndLocation, FMath::Clamp(ElapsedTime / Duration, 0.0f, 1.0f));

	// Set the new actor location for the upward movement
	SetActorLocation(NewLocationUp);
}

void APDEnemy::RookMove()
{
	// Simulate the Queen's move (200 units up, Left, Right, or down then)
	const int32 Direction = FMath::RandRange(0,3); // 4 directions
	float XDirection = 0;
	float YDirection = 0;
	switch (Direction)
	{
	case 0:
		// Move Left
		YDirection -= MoveRange;
		break;
	case 1:
		// Move Right
		YDirection += MoveRange;
		break;
	case 2:
		// Move Up
		XDirection += MoveRange;
		break;
	default:
		// Move Down
		XDirection -= MoveRange;
		break;
	}
	const FVector StartLocation = GetActorLocation();
	const FVector EndLocation = StartLocation + FVector(XDirection, YDirection, 0.f); // Move 200 units up
	const float Duration = 1.0f;
	const float ElapsedTime = 5.0f;

	// Interpolate for the upward movement
	const FVector NewLocationUp = FMath::Lerp(StartLocation, EndLocation, FMath::Clamp(ElapsedTime / Duration, 0.0f, 1.0f));

	// Set the new actor location for the upward movement
	SetActorLocation(NewLocationUp);
}

void APDEnemy::KnightMove()
{
	// Simulate the knight's move (200 units up then 200 units right)
	const FVector StartLocation = GetActorLocation();
	const FVector EndLocation = StartLocation + FVector(0, MoveRange, 0); // Move 200 units up
	const float Duration = 1.0f;
	const float ElapsedTime = 5.0f;

	// Interpolate for the upward movement
	const FVector NewLocationUp = FMath::Lerp(StartLocation, EndLocation, FMath::Clamp(ElapsedTime / Duration, 0.0f, 1.0f));

	// Set the new actor location for the upward movement
	SetActorLocation(NewLocationUp);

	FTimerHandle MoveDelayTimer;
	const FTimerDelegate MoveRightDelegate = FTimerDelegate::CreateLambda([this]() {
		const float Duration = 1.0f;
		const float ElapsedTime = 5.0f;
		const float Direction = FMath::RandBool() == true ? MoveRange : -MoveRange;
		const FVector NewEndLocation = GetActorLocation() + FVector(Direction, 0, 0); // Move 200 units right or left
		// Interpolate for the upward movement
		const FVector NewLocationRight = FMath::Lerp(GetActorLocation(), NewEndLocation, FMath::Clamp(ElapsedTime / Duration, 0.0f, 1.0f));
		SetActorLocation(NewLocationRight);
	});

	// Delay the second part of the move
	GetWorldTimerManager().SetTimer(MoveDelayTimer, MoveRightDelegate, 1.0f, false);
}

void APDEnemy::QueenMove()
{
	// Simulate the Queen's move (200 units up, Left, Right, or down then)
	const int32 Direction = FMath::RandRange(0,7); // 8 moves
	float XDirection = 0;
	float YDirection = 0;
	switch (Direction)
	{
		case 0:
			// Move Up Left
			XDirection += MoveRange;
			YDirection -= MoveRange;
			break;
		case 1:
			// Move Up Right
			XDirection += MoveRange;
			YDirection += MoveRange;
			break;
		case 2:
			// Move Down Left
			XDirection -= MoveRange;
			YDirection -= MoveRange;
			break;
		case 3:
			// Move Down Right
			XDirection -= MoveRange;
			YDirection += MoveRange;
			break;
		case 4:
			// Move Left
			YDirection -= MoveRange;
			break;
		case 5:
			// Move Right
			YDirection += MoveRange;
			break;
		case 6:
			// Move Up
			XDirection += MoveRange;
			break;
		default:
			// Move Down
			XDirection -= MoveRange;
			break;
	}
	const FVector StartLocation = GetActorLocation();
	const FVector EndLocation = StartLocation + FVector(XDirection, YDirection, 0.f); // Move 200 units up
	const float Duration = 1.0f;
	const float ElapsedTime = 5.0f;

	// Interpolate for the upward movement
	const FVector NewLocationUp = FMath::Lerp(StartLocation, EndLocation, FMath::Clamp(ElapsedTime / Duration, 0.0f, 1.0f));

	// Set the new actor location for the upward movement
	SetActorLocation(NewLocationUp);
}

void APDEnemy::KingMove()
{
	RookMove();
}


void APDEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Hp <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Enemy Died"));
	}
}
