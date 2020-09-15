// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioMaturityOption.generated.h"

UENUM(Meta = (Bitflags))
enum class EModioMaturityOption
{
  ALCOHOL   UMETA(DisplayName = "Alcohol"),
  DRUGS     UMETA(DisplayName = "Drugs"),
  VIOLENCE  UMETA(DisplayName = "Violence"),
  EXPLICIT  UMETA(DisplayName = "Explicit"),
  UNDEFINED UMETA(DisplayName = "Undefined (default)")
};