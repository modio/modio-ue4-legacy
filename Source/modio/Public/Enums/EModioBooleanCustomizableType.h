// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "EModioBooleanCustomizableType.generated.h"

UENUM(BlueprintType)
enum EModioBooleanCustomizableType
{
  UNDEFINED     UMETA(DisplayName = "Undefined"),
  SET_TO_TRUE   UMETA(DisplayName = "True"),
  SET_TO_FALSE  UMETA(DisplayName = "False")
};