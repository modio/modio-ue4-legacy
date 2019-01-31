#pragma once

#include "modio.h"
#include "FModioDownload.generated.h"

USTRUCT(BlueprintType)
struct FModioDownload
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateExpires;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString BinaryUrl;
};

extern void initializeDownload(FModioDownload &download, modio::Download modio_download);
extern void initializeDownloadC(FModioDownload &download, ModioDownload modio_download);