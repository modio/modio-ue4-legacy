// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Int64.h"
#include "CoreMinimal.h"
#include "c/ModioC.h"
#include "Schemas/ModioMod.h"
#include "ModioQueuedModDownload.generated.h"

USTRUCT(BlueprintType)
struct FModioQueuedModDownload
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Path;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FInt64 CurrentProgress;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FInt64 TotalSize;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioMod mod;
};

extern void InitializeQueuedModDownload(FModioQueuedModDownload &queued_mod_download, const ModioQueuedModDownload &modio_queued_mod_download);
