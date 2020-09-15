// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioFieldFilterType.generated.h"

UENUM(BlueprintType)
enum EModioFieldFilterType
{
  FIELD_FILTER_EQUAL        UMETA(DisplayName = "Equal"),
  FIELD_FILTER_NOT_EQUAL    UMETA(DisplayName = "Not equal"),
  FIELD_FILTER_LIKE         UMETA(DisplayName = "Like"),
  FIELD_FILTER_NOT_LIKE     UMETA(DisplayName = "Not like"),
  FIELD_FILTER_IN           UMETA(DisplayName = "In"),
  FIELD_FILTER_NOT_IN       UMETA(DisplayName = "Not in"),
  FIELD_FILTER_MIN          UMETA(DisplayName = "Min than"),
  FIELD_FILTER_MAX          UMETA(DisplayName = "Max than"),
  FIELD_FILTER_SMALLER_THAN UMETA(DisplayName = "Smaller than"),
  FIELD_FILTER_GREATER_THAN UMETA(DisplayName = "Greather than")
};