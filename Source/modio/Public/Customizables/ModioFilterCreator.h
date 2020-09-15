// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Customizables/ModioFieldFilterCreator.h"
#include "Customizables/ModioSortCreator.h"
#include "Runtime/Core/Public/Containers/Map.h"
#include "ModioFilterCreator.generated.h"

USTRUCT(BlueprintType)
struct FModioFilterCreator
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioSortCreator Sort;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString FullTextSearch;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TArray <FModioFieldFilterCreator> FieldFilters;
};