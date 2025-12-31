// Fill out your copyright notice in the Description page of Project Settings.


#include "Goal.h"
#include "Ball.h"
#include "PongGameMode.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGoal::AGoal()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    GoalMesh = CreateDefaultSubobject<UStaticMeshComponent>("Goal Mesh");
    RootComponent = GoalMesh;

    GoalMesh->SetSimulatePhysics(false);
    GoalMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    GoalMesh->SetCollisionProfileName("OverlapAll");
}

// Called when the game starts or when spawned
void AGoal::BeginPlay()
{
    Super::BeginPlay();
    OnActorBeginOverlap.AddDynamic(this, &AGoal::OnOverlap);
}

void AGoal::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
    ABall* Ball = Cast<ABall>(OtherActor);
    if (Ball)
    {
        APongGameMode* GameMode = Cast<APongGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
        if (GameMode)
        {
            if (bIsPlayerGoal)
            {
                GameMode->IncreaseAIScore();
            }
            else
            {
                GameMode->IncreasePlayerScore();
            }
        }

        Ball->ResetBall();
    }
}

// Called every frame
void AGoal::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}
