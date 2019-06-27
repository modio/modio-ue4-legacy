// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Engine.h"
#include "modio.h"
#include "ModioQUeuedModfileUpload.generated.h"

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

extern void InitializeQueuedModfileUpload(FModioQueuedModfileUpload &queued_modfile_upload, const ModioQueuedModfileUpload &modio_queued_modfile_upload);