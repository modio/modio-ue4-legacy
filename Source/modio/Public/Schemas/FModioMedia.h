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

extern void initializeMedia(FModioMedia &media, modio::Media modio_media);
extern void initializeMediaC(FModioMedia &media, ModioMedia modio_media);