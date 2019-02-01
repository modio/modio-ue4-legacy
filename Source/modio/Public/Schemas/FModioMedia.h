// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "modio.h"
#include "FModioImage.h"
#include "FModioMedia.generated.h"

USTRUCT(BlueprintType)
struct FModioMedia
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TArray<FString> Youtube;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TArray<FString> Sketchfab;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TArray<FModioImage> Images;
};

extern void InitializeMedia(FModioMedia &media, modio::Media modio_media);
extern void InitializeMediaC(FModioMedia &media, ModioMedia modio_media);