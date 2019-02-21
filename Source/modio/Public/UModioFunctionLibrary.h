// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"
#include "ModioCallbacks.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UModioFunctionLibrary.generated.h"

UCLASS()
class MODIO_API UModioFunctionLibrary : public UBlueprintFunctionLibrary
{
  GENERATED_UCLASS_BODY()

  // Process

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioProcess();

  // Authentication

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioLogout();

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioIsLoggedIn(bool &is_logged_in);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioCurrentUser(FModioUser &user);

  // Downloads and installs

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetAllInstalledMod(TArray<FModioInstalledMod> &installed_mods);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetModDownloadQueue(TArray<FModioQueuedModDownload> &queued_mods);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioInstallDownloadedMods();
  
  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioAddModfile(int32 mod_id, FModioModfileCreator modfile_creator);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetModfileUploadQueue(TArray<FModioQueuedModfileUpload> &upload_queue);

  // @todo migrate to callback proxies
  
  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioGetAuthenticatedUser();
};