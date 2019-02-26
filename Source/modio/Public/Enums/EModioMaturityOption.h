// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "EModioMaturityOption.generated.h"

UENUM(Meta = (Bitflags))
enum class EModioMaturityOption
{
  ALCOHOL  UMETA(DisplayName = "Alcohol"),
  DRUGS    UMETA(DisplayName = "Drugs"),
  VIOLENCE UMETA(DisplayName = "Violence"),
  EXPLICIT UMETA(DisplayName = "Explicit")
};