// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

APongGameMode::APongGameMode()
{
    PlayerScore = 0;
    AIScore = 0;
}

void APongGameMode::IncreasePlayerScore()
{
    PlayerScore++;
}

void APongGameMode::IncreaseAIScore()
{
    AIScore++;
}

void APongGameMode::BeginPlay()
{
    Super::BeginPlay();
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    //Find the Actor in the level that has the camera component
    ACameraActor* ActorWhereMyCameraIs = Cast<ACameraActor>(UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass()));
    if (ActorWhereMyCameraIs)
    {
        //Transitions to camera with animation
        //PC->SetViewTargetWithBlend(ActorWhereMyCameraIs, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
        //Snaps to camera 
        PC->SetViewTarget(ActorWhereMyCameraIs);
        //
    }
}
