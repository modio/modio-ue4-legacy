// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "Schemas/ModioGameTagOption.h"
#include "Schemas/ModioUser.h"
#include "Schemas/ModioLogo.h"
#include "ModioGame.generated.h"

struct ModioMod;
struct ModioHeader;
struct ModioIcon;

USTRUCT(BlueprintType)
struct FModioIcon
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Filename;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Original;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb64x64;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb128x128;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Thumb256x256;
};

USTRUCT(BlueprintType)
struct FModioHeaderImage
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Filename;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Original;
};

USTRUCT(BlueprintType)
struct FModioGame
{
  GENERATED_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Id;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 Status;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioUser SubmittedBy;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateAdded;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateUpdated;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 DateLive;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 PresentationOption;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 SubmissionOption;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 CurationOption;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 CommunityOptions;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 RevenueOptions;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 ApiAccessOptions;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  int32 MaturityOptions;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString UGCName;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioIcon Icon;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioLogo Logo;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FModioHeaderImage Header;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Name;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString NameId;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Summary;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString Instructions;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString InstructionsUrl;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  FString ProfileUrl;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
  TArray<FModioGameTagOption> TagOptions;
};

extern void InitializeGame(FModioGame& game, const ModioGame& modio_game);
extern void InitializeHeaderImage(FModioHeaderImage& headerImage, const ModioHeader& modio_header_image);
extern void InitializeIcon(FModioIcon& icon, const ModioIcon& modio_icon);

DECLARE_DELEGATE_TwoParams(FModioGameDelegate, FModioResponse, FModioGame);
