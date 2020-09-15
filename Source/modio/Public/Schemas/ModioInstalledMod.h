// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "c/ModioC.h"
#include "Schemas/ModioMod.h"
#include "ModioInstalledMod.generated.h"

USTRUCT(BlueprintType)
struct FModioInstalledMod
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Path;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioMod Mod;
};

extern void InitializeInstalledMod(FModioInstalledMod &installed_mod, const ModioInstalledMod &modio_installed_mod);