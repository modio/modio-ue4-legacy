// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Enums/ModioFieldFilterType.h"
#include "Runtime/Core/Public/Containers/Map.h"
#include "ModioFieldFilterCreator.generated.h"

USTRUCT(BlueprintType)
struct FModioFieldFilterCreator
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Field;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TEnumAsByte<EModioFieldFilterType> Type;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Value;
};