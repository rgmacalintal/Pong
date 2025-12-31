// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PongGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RMPONG_API APongGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    APongGameMode();

    UPROPERTY(BlueprintReadOnly)
    int32 PlayerScore;

    UPROPERTY(BlueprintReadOnly)
    int32 AIScore;

    UFUNCTION(BlueprintCallable)
    void IncreasePlayerScore();

    UFUNCTION(BlueprintCallable)
    void IncreaseAIScore();

protected:
    virtual void BeginPlay() override;
};

