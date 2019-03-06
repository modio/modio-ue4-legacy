// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "FModioInstalledMod.h"
#include "FModioQueuedModDownload.h"
#include "FModioModfileCreator.h"
#include "FModioQueuedModfileUpload.h"
#include "ModioCallbacks.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Delegates.h"
#include "ModioFunctionLibrary.generated.h"

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
  static void ModioIsLoggedIn(bool &IsLoggedIn);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioCurrentUser(FModioUser &User);

  // Downloads and installs

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetAllInstalledMod(TArray<FModioInstalledMod> &InstalledMods);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetModDownloadQueue(TArray<FModioQueuedModDownload> &QueuedMods);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioInstallDownloadedMods();
  
  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioAddModfile(int32 ModId, FModioModfileCreator ModfileCreator);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetModfileUploadQueue(TArray<FModioQueuedModfileUpload> &UploadQueue);

  static void EmailRequest(FString Email, FEmailRequestDelegate Delegate);
};