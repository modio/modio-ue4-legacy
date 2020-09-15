// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "c/ModioC.h"
#include "Schemas/ModioResponse.h"
#include "ModioUserEvent.generated.h"

USTRUCT(BlueprintType)
struct FModioUserEvent
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 GameId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 ModId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 UserId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 EventType;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateAdded;
};

extern void InitializeUserEvent(FModioUserEvent &UserEvent, const ModioUserEvent &ModioUserEvent);

DECLARE_DELEGATE_TwoParams( FModioUserEventDelegate, FModioResponse, FModioUserEvent );
DECLARE_DELEGATE_TwoParams( FModioUserEventArrayDelegate, FModioResponse, const TArray<FModioUserEvent> & );