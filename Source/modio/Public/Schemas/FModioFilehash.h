#pragma once

#include "modio.h"
#include "FModioFilehash.generated.h"

USTRUCT(BlueprintType)
struct FModioFilehash
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Md5;
};

extern void initializeFilehash(FModioFilehash &filehash, modio::Filehash modio_filehash);
extern void initializeFileHashC(FModioFilehash &filehash, ModioFilehash modio_filehash);