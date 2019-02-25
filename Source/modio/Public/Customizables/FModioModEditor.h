// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Enums/EModioBooleanCustomizableType.h"
#include "FModioModEditor.generated.h"

USTRUCT(BlueprintType)
struct FModioModEditor
{
  GENERATED_BODY()
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Name = "";
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
  FString CreatorTag = "";
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TEnumAsByte<EModioBooleanCustomizableType> Visible;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io", Meta = (Bitmask, BitmaskEnum = "EModioMaturityOption"))
  int32 MaturityOption = 0;
};