#pragma once

#include "modio.h"
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

extern void initializeKVP(FModioMetadataKVP &metadata_kvp, modio::MetadataKVP modio_metadata_kvp);
extern void initializeKVPC(FModioMetadataKVP &metadata_kvp, ModioMetadataKVP modio_metadata_kvp);