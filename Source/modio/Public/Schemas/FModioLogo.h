#pragma once

#include "modio.h"
#include "FModioLogo.generated.h"

USTRUCT(BlueprintType)
struct FModioLogo
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Filename;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Original;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb320x180;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb640x360;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb1280x720;
};

extern void initializeLogo(FModioLogo &Logo, modio::Logo modio_logo);
extern void initializeLogoC(FModioLogo &Logo, ModioLogo modio_logo);