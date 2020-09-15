// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioModSortType.generated.h"

UENUM(BlueprintType)
enum EModioModSortType
{
  SORT_BY_ID            UMETA(DisplayName = "Sort by id"),
  SORT_BY_DATE_ADDED    UMETA(DisplayName = "Sort by date added"),
  SORT_BY_DATE_UPDATED  UMETA(DisplayName = "Sort by date updated"),
  SORT_BY_DATE_LIVE     UMETA(DisplayName = "Sort by date live"),
  SORT_BY_NAME          UMETA(DisplayName = "Sort by name"),
  SORT_BY_DOWNLOADS     UMETA(DisplayName = "Sort by downloads"),
  SORT_BY_POPULAR       UMETA(DisplayName = "Sort by popular"),
  SORT_BY_RATING        UMETA(DisplayName = "Sort by rating"),
  SORT_BY_SUBSCRIBERS   UMETA(DisplayName = "Sort by subscribers")
};