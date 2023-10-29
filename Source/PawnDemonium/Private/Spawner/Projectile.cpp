// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner/Projectile.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Characters/PDEnemy.h"
#include "Engine/DamageEvents.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));
    RootComponent = CollisionComponent;

    ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMesh");
    ProjectileMeshComponent->SetupAttachment(GetRootComponent());

    ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
    ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
    ProjectileMovementComponent->InitialSpeed = ProjectileSpeed;
    ProjectileMovementComponent->MaxSpeed = ProjectileSpeed;
    ProjectileMovementComponent->bRotationFollowsVelocity = true;
    ProjectileMovementComponent->bShouldBounce = false;

    bReplicates = true;
    SetReplicateMovement(true);
    

}

void AProjectile::SetShootingDirection(const FVector& Direction)
{
    ProjectileMovementComponent->Velocity = Direction * ProjectileSpeed;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

    // Set the projectile's initial movement and direction
    SetActorRotation(ShootingDirection.Rotation());
    SetLifeSpan(5.0f); // Set a lifespan for the projectile to self-destruct after a certain time

    // Projectile movement
    ProjectileMovementComponent->SetVelocityInLocalSpace(ShootingDirection * ProjectileSpeed);
    ProjectileMovementComponent->Activate();
}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    if (OtherActor && OtherActor->IsA(APDEnemy::StaticClass()))
    {
        UE_LOG(LogTemp, Warning, TEXT("Projectile Hit Enemy"));
        APDEnemy* HitEnemy = Cast<APDEnemy>(OtherActor);
        if (HitEnemy)
        {
            HitEnemy->TakeDamage(10, FDamageEvent(), GetInstigatorController(), this);
        }
    }
    Destroy();
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

