#pragma once

#include "modio.h"
#include "FModioMod.h"
#include "FModioInstalledMod.generated.h"

USTRUCT(BlueprintType)
struct FModioInstalledMod
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Path;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioMod mod;
};

extern void initializeInstalledModC(FModioInstalledMod &installed_mod, ModioInstalledMod modio_installed_mod);