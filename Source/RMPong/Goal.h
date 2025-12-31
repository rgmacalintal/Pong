// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Goal.generated.h"

UCLASS()
class RMPONG_API AGoal : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AGoal();

    /*UPROPERTY(VisibleAnywhere)
    class UBoxComponent* GoalBox;*/

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Goal")
    class UStaticMeshComponent* GoalMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Goal")
    bool bIsPlayerGoal;

    UFUNCTION()
    void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);

    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
};

