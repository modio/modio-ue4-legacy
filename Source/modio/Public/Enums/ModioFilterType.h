// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioFilterType.generated.h"

UENUM(BlueprintType)
enum EModioFilterType
{
  SORT_BY_ID            UMETA(DisplayName = "Sort by id"),
  SORT_BY_RATING        UMETA(DisplayName = "Sort by rating"),
  SORT_BY_DATE_LIVE     UMETA(DisplayName = "Sort by date live"),
  SORT_BY_DATE_UPDATED  UMETA(DisplayName = "Sort by date updated")
};