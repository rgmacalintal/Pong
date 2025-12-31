// Fill out your copyright notice in the Description page of Project Settings.


#include "PongHUD.h"
#include "Engine/Canvas.h"
#include "PongGameMode.h"
#include "Kismet/GameplayStatics.h"

void APongHUD::DrawHUD()
{
    Super::DrawHUD();

    APongGameMode* GameMode = Cast<APongGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

    if (GameMode)
    {
        FString ScoreText = FString::Printf(TEXT("Player: %d    AI: %d"), GameMode->PlayerScore, GameMode->AIScore);

        FVector2D ScreenCenter(Canvas->SizeX / 2.f, 50.f);

        FCanvasTextItem TextItem(ScreenCenter, FText::FromString(ScoreText), GEngine->GetLargeFont(), FLinearColor::White);
        TextItem.bCentreX = true;

        Canvas->DrawItem(TextItem);
    }
}

