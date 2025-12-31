// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPaddle.h"

APlayerPaddle::APlayerPaddle()
{
    PrimaryActorTick.bCanEverTick = true;

    PaddleMesh = CreateDefaultSubobject<UStaticMeshComponent>("PaddleMesh");
    RootComponent = PaddleMesh;
    PaddleMesh->SetCollisionProfileName("Pawn");
    PaddleMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    PaddleMesh->SetSimulatePhysics(true);
    MovementSpeed = 600.f;

    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void APlayerPaddle::BeginPlay()
{
    Super::BeginPlay();
}

void APlayerPaddle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APlayerPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveUp", this, &APlayerPaddle::MoveUp);
}

void APlayerPaddle::MoveUp(float AxisValue)
{
    FVector NewLocation = GetActorLocation();
    NewLocation.X += AxisValue * MovementSpeed * GetWorld()->GetDeltaSeconds();
    SetActorLocation(NewLocation);
}

