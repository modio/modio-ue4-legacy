#pragma once

#include "modio.h"
#include "FModioImage.generated.h"

USTRUCT(BlueprintType)
struct FModioImage
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Filename;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Original;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb320x180;
};

extern void initializeImage(FModioImage &image, modio::Image modio_image);
extern void initializeImageC(FModioImage &image, ModioImage modio_image);