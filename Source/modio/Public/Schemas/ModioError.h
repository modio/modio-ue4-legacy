// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Engine.h"
#include "modio.h"
#include "ModioError.generated.h"

USTRUCT(BlueprintType)
struct FModioError
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Code;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Message;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TArray<FString> Errors;
};

extern void InitializeError(FModioError &error, const ModioError &modio_error);