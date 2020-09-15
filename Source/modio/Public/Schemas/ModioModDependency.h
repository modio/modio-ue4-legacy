// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "c/ModioC.h"
#include "Schemas/ModioResponse.h"
#include "ModioModDependency.generated.h"

USTRUCT(BlueprintType)
struct FModioModDependency
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 ModId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateAdded;
};

extern void InitializeModDependency(FModioModDependency &ModDependency, const ModioDependency &ModioDependency);

DECLARE_DELEGATE_TwoParams( FModioModDependencyArrayDelegate, FModioResponse, const TArray<FModioModDependency> & );