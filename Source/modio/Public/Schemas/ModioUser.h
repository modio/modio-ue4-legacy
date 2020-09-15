// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "c/ModioC.h"
#include "Schemas/ModioAvatar.h"
#include "Schemas/ModioResponse.h"
#include "ModioUser.generated.h"

USTRUCT(BlueprintType)
struct FModioUser
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateOnline;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Username;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString NameId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Timezone;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Language;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString ProfileUrl;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioAvatar Avatar;
};

extern void InitializeUser(FModioUser &User, const ModioUser &modio_user);

DECLARE_DELEGATE_TwoParams( FModioUserDelegate, FModioResponse, FModioUser );