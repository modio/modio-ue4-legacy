// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Enums/ModioBooleanCustomizableType.h"
#include "Enums/ModioMaturityOption.h"
#include "ModioModCreator.generated.h"

USTRUCT(BlueprintType)
struct FModioModCreator
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Name = "";
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString LogoPath = "";
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Summary = "";
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString NameId = "";
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Description = "";
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString HomepageUrl = "";
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString MetadataBlob = "";
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TArray<FString> Tags;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TEnumAsByte<EModioBooleanCustomizableType> Visible;
  // @todo Find a workaround to ue4 bitmask and enums issues
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io", Meta = (Bitmask, BitmaskEnum = "EModioMaturityOption"))
  int32 MaturityOption = 16;
};