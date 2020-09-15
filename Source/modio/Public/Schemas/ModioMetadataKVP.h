// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "c/ModioC.h"
#include "Schemas/ModioResponse.h"
#include "ModioMetadataKVP.generated.h"

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

DECLARE_DELEGATE_TwoParams( FModioMetadataKVPDelegate, FModioResponse, FModioMetadataKVP );
DECLARE_DELEGATE_TwoParams( FModioMetadataKVPArrayDelegate, FModioResponse, const TArray<FModioMetadataKVP> & );