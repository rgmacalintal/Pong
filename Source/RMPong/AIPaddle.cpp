// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPaddle.h"

// Sets default values
AAIPaddle::AAIPaddle()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>("PaddleMesh");
    RootComponent = PaddleMesh;
    PaddleMesh->SetCollisionProfileName("Pawn");
    PaddleMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    PaddleMesh->SetSimulatePhysics(true);

    MovementSpeed = 300.f;
}

// Called when the game starts or when spawned
void AAIPaddle::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AAIPaddle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (TargetBall)
    {
        TrackBall(DeltaTime);
    }
}

void AAIPaddle::TrackBall(float DeltaTime)
{
    FVector BallLocation = TargetBall->GetActorLocation();
    FVector NewLocation = GetActorLocation();

    float OldY = NewLocation.Y;

    if (BallLocation.X > NewLocation.X + 10.f)
    {
        NewLocation.X += MovementSpeed * DeltaTime;
    }
    else if (BallLocation.X < NewLocation.X - 10.f)
    {
        NewLocation.X -= MovementSpeed * DeltaTime;
    }

    NewLocation.Z = 0.f;
    NewLocation.Y = OldY;

    SetActorLocation(NewLocation);
}

