// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Enums/ModioModSortType.h"
#include "ModioSortCreator.generated.h"

USTRUCT(BlueprintType)
struct FModioSortCreator
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TEnumAsByte<EModioModSortType> ModSortType;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  bool Ascending;
};