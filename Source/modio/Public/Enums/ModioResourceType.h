// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioResourceType.generated.h"

UENUM(BlueprintType)
enum EModioResourceType
{
  GAMES UMETA(DisplayName = "Games"),
  MODS  UMETA(DisplayName = "Mods"),
  USERS UMETA(DisplayName = "Users")
};