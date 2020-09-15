// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioRatingType.generated.h"

UENUM(BlueprintType)
enum EModioRatingType
{
  RATING_NOT_DEFINED   UMETA(DisplayName = "Not defined"),
  RATING_NEGATIVE      UMETA(DisplayName = "Negative"),
  RATING_POSITIVE      UMETA(DisplayName = "Positive")
};