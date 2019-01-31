#pragma once

#include "FModioModfileCreator.generated.h"

USTRUCT(BlueprintType)
struct FModioModfileCreator
{
  GENERATED_BODY()
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Path;
};