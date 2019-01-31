#pragma once

#include "modio.h"
#include "FModioMod.h"
#include "FModioQueuedModDownload.generated.h"

USTRUCT(BlueprintType)
struct FModioQueuedModDownload
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Path;
  // TODO: change to int64 unsupported by ue4
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 CurrentProgress;
  // TODO: change to int64 unsupported by ue4
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 TotalSize;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioMod mod;
};

extern void initializeQueuedModDownloadC(FModioQueuedModDownload &queued_mod_download, ModioQueuedModDownload modio_queued_mod_download);
