// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "modio.h"
#include "FModioLogo.h"
#include "FModioUser.h"
#include "FModioModfile.h"
#include "FModioMedia.h"
#include "FModioStats.h"
#include "FModioTag.h"
#include "FModioMetadataKVP.h"
#include "FModioMod.generated.h"

USTRUCT(BlueprintType)
struct FModioMod
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 GameId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Status;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Visible;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 MaturityOption;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateAdded;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateUpdated;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateLive;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString HomepageUrl;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Name;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString NameId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Summary;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Description;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString DescriptionPlainText;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString MetadataBlob;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString ProfileUrl;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioLogo Logo;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioUser SubmittedBy;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioModfile Modfile;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioMedia Media;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioStats Stats;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TArray<FModioTag> Tags;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TArray<FModioMetadataKVP> MetadataKVP;
};

extern void InitializeMod(FModioMod &mod, modio::Mod modio_mod);
extern void InitializeModC(FModioMod &mod, ModioMod modio_mod);