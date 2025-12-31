// Fill out your copyright notice in the Description page of Project Settings.


#include "PongPlayerController.h"
#include "PlayerPaddle.h"

void APongPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    InputComponent->BindAxis("MoveUp", this, &APongPlayerController::MoveUp);
}

void APongPlayerController::MoveUp(float AxisValue)
{
    APlayerPaddle* Paddle = Cast<APlayerPaddle>(GetPawn());
    if (Paddle)
    {
        Paddle->MoveUp(AxisValue);
    }
}

