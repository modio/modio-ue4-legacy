// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "c/ModioC.h"
#include "Schemas/ModioResponse.h"
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

DECLARE_DELEGATE_TwoParams( FModioModTagArrayDelegate, FModioResponse, const TArray<FModioModTag> & );