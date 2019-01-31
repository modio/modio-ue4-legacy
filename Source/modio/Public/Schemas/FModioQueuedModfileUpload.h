#pragma once

#include "modio.h"
#include "FModioQUeuedModfileUpload.generated.h"

USTRUCT(BlueprintType)
struct FModioQueuedModfileUpload
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 State;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 ModId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 CurrentProgress;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 TotalSize;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Path;
};

extern void initializeQueuedModfileUploadC(FModioQueuedModfileUpload &queued_modfile_upload, ModioQueuedModfileUpload modio_queued_modfile_upload);