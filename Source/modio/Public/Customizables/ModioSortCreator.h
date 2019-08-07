// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSortCreator.generated.h"

USTRUCT(BlueprintType)
struct FModioSortCreator
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Field;
  bool Ascending;
};