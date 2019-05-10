// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioResponse.h"
#include "ModioHWrapper.h"
#include "ModioModTag.generated.h"

USTRUCT(BlueprintType)
struct FModioModTag
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateAdded;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Name;
};

extern void InitializeModTag(FModioModTag &tag, const ModioTag &modio_tag);

DECLARE_DELEGATE_TwoParams( FModioModTagsArrayDelegate, FModioResponse, const TArray<FModioModTag> & );