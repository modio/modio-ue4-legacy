// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioHWrapper.h"
#include "FModioFilehash.generated.h"

USTRUCT(BlueprintType)
struct FModioFilehash
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Md5;
};

extern void InitializeFilehash(FModioFilehash &filehash, const ModioFilehash &modio_filehash);