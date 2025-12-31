// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ball.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AIPaddle.generated.h"

UCLASS()
class RMPONG_API AAIPaddle : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    AAIPaddle();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="PaddleMesh")
    UStaticMeshComponent* PaddleMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovementSpeed")
    float MovementSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetBall")
    ABall* TargetBall;

    void TrackBall(float DeltaTime);

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

};
