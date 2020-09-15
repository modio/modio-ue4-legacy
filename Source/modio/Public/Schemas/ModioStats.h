// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "c/ModioC.h"
#include "ModioStats.generated.h"

USTRUCT(BlueprintType)
struct FModioStats
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 ModId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 PopularityRankPosition;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 PopularityRankTotalMods;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DownloadsTotal;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 SubscribersTotal;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 RatingsTotal;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 RatingsPositive;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 RatingsNegative;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 RatingsPercentagePositive;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateExpires;
  // @todo: should this be switched to double?
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  float RatingsWeightedAggregate;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString RatingsDisplayText;
};

extern void InitializeStats(FModioStats &stats, const ModioStats &modio_stats);