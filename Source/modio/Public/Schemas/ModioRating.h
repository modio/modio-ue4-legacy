// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Int64.h"
#include "CoreMinimal.h"
#include "c/ModioC.h"
#include "Schemas/ModioResponse.h"
#include "ModioRating.generated.h"

USTRUCT(BlueprintType)
struct FModioRating
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 GameId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 ModId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Rating;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateAdded;
};

extern void InitializeRating(FModioRating &rating, const ModioRating &modio_rating);

DECLARE_DELEGATE_TwoParams( FModioRatingDelegate, FModioResponse, FModioRating );
DECLARE_DELEGATE_TwoParams( FModioRatingArrayDelegate, FModioResponse, const TArray<FModioRating> & );