// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "ModioGameTagOption.generated.h"

struct ModioGameTagOption;

USTRUCT(BlueprintType)
struct FModioGameTagOption
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString		  Name;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString		  Type;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  bool			  Hidden;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TArray<FString> Tags;
};

extern void InitializeGameTagOption(FModioGameTagOption& tag, const ModioGameTagOption& modio_game_tag_option);