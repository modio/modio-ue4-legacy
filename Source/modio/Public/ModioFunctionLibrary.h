// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioSubsystem.h"
#include "Schemas/ModioInstalledMod.h"
#include "Schemas/ModioQueuedModDownload.h"
#include "Schemas/ModioQueuedModfileUpload.h"
#include "Customizables/ModioModfileCreator.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ModioFunctionLibrary.generated.h"

UCLASS()
class MODIO_API UModioFunctionLibrary : public UBlueprintFunctionLibrary
{
  GENERATED_UCLASS_BODY()

  // Process

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioProcess(UObject *WorldContextObject);

  // Configuration

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioSetModEventsPollInterval(UObject *WorldContextObject, int32 IntervalInSeconds);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioSetUserEventsPollInterval(UObject *WorldContextObject, int32 IntervalInSeconds);

  // Authentication

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioLogout(UObject *WorldContextObject);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioIsLoggedIn(UObject *WorldContextObject, bool &IsLoggedIn);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioCurrentUser(UObject *WorldContextObject, FModioUser &User);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void AuthenticateViaToken(UObject *WorldContextObject, const FString& AccessToken);

  // Downloads and installs

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetInstalledMod(UObject *WorldContextObject, int32 ModId, FString &Path, FModioMod &Mod);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetAllInstalledMods(UObject *WorldContextObject, TArray<FModioInstalledMod> &InstalledMods);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetAllDownloadedMods(UObject *WorldContextObject, TArray<int32> &DownloadedMods);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetModDownloadQueue(UObject *WorldContextObject, TArray<FModioQueuedModDownload> &QueuedMods);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioInstallDownloadedMods(UObject *WorldContextObject);
  
  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioAddModfile(UObject *WorldContextObject, int32 ModId, FModioModfileCreator ModfileCreator);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetModfileUploadQueue(UObject *WorldContextObject, TArray<FModioQueuedModfileUpload> &UploadQueue);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetModState(UObject *WorldContextObject, int32 ModId, uint8 &ModState);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetUserModRating(UObject *WorldContextObject, int32 ModId, uint8 &ModRating);
};