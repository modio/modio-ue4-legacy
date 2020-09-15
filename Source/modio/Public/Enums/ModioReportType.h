// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioReportType.generated.h"

UENUM(BlueprintType)
enum EModioReportType
{
  GENERIC   UMETA(DisplayName = "Generic"),
  DMCA      UMETA(DisplayName = "DMCA")
};