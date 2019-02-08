// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioHWrapper.h"
#include "FModioMetadataKVP.generated.h"

USTRUCT(BlueprintType)
struct FModioMetadataKVP
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Metakey;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Metavalue;
};

extern void InitializeMetadataKVP( FModioMetadataKVP &MetadataKVP, const ModioMetadataKVP &modio_metadata_kvp );