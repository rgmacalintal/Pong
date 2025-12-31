// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Wall.h"
#include "PlayerPaddle.h"
#include "AIPaddle.h"

ABall::ABall()
{
    PrimaryActorTick.bCanEverTick = true;

    BallMesh = CreateDefaultSubobject<UStaticMeshComponent>("BallMesh");
    RootComponent = BallMesh;

    BallMesh->SetSimulatePhysics(false);
    BallMesh->SetNotifyRigidBodyCollision(true);
    BallMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    BallMesh->SetCollisionProfileName("BlockAllDynamic");
    BallMesh->OnComponentHit.AddDynamic(this, &ABall::OnHit);

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
    ProjectileMovement->InitialSpeed = 600.f;
    ProjectileMovement->MaxSpeed = 800.f;
    ProjectileMovement->bShouldBounce = true;
    ProjectileMovement->Bounciness = 1.0f;
    ProjectileMovement->Friction = 0.f;
    ProjectileMovement->Velocity = FVector(600.f, -600.f, 0.f);

}

void ABall::BeginPlay()
{
    Super::BeginPlay();
    ProjectileMovement->Velocity = FVector(600.f, -600.f, 0.f);
}

void ABall::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ABall::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}

void ABall::ResetBall()
{
    SetActorLocation(FVector(0.f, 0.f, 50.f));

    ProjectileMovement->Velocity = FVector(600.f, -600.f, 0.f);
    ProjectileMovement->Activate(true);
}

