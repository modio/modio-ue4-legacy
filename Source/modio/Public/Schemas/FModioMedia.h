// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioHWrapper.h"
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

extern void InitializeMedia(FModioMedia &media, const modio::Media &modio_media);
extern void InitializeMediaC(FModioMedia &media, const ModioMedia &modio_media);