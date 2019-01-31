#pragma once

#include "modio.h"
#include "FModioAvatar.generated.h"

USTRUCT(BlueprintType)
struct FModioAvatar
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Filename;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Original;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb50x50;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb100x100;
};

extern void initializeAvatar(FModioAvatar &Avatar, modio::Avatar modio_avatar);
extern void initializeAvatarC(FModioAvatar &Avatar, ModioAvatar modio_avatar);