// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "c/ModioC.h"
#include "Schemas/ModioResponse.h"
#include "ModioModEvent.generated.h"

USTRUCT(BlueprintType)
struct FModioModEvent
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 ModId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 UserId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 EventType;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateAdded;
};

extern void InitializeModEvent(FModioModEvent &event, const ModioModEvent &modio_event);

DECLARE_DELEGATE_TwoParams( FModioModEventDelegate, FModioResponse, FModioModEvent );
DECLARE_DELEGATE_TwoParams( FModioModEventArrayDelegate, FModioResponse, const TArray<FModioModEvent> & );