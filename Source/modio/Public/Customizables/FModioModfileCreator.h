// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Enums/EModioBooleanCustomizableType.h"
#include "FModioModfileCreator.generated.h"

USTRUCT(BlueprintType)
struct FModioModfileCreator
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Path = "";
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Version = "";
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Changelog = "";
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TEnumAsByte<EModioBooleanCustomizableType> Active;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Filehash = "";
};