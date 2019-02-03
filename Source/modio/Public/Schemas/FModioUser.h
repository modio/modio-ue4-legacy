// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioHWrapper.h"
#include "FModioAvatar.h"
#include "FModioUser.generated.h"

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

extern void InitializeUser(FModioUser &User, const modio::User &modio_user);
extern void InitializeUserC(FModioUser &User, const ModioUser &modio_user);