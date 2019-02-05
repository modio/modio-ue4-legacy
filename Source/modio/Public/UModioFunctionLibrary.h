// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "ModioCallbacks.h"
#include "Enums/EModioFilterType.h"
#include "Customizables/FModioModfileCreator.h"
#include "Customizables/FModioModEditor.h"
#include "Customizables/FModioModCreator.h"
#include "Schemas/FModioQueuedModfileUpload.h"
#include "Schemas/FModioQueuedModDownload.h"
#include "Schemas/FModioInstalledMod.h"
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
  static void ModioEmailRequest(FString email);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioEmailExchange(FString security_code);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioLogout();

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioIsLoggedIn(bool &is_logged_in);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioCurrentUser(FString &username);

  // Downloads and installs

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetAllInstalledMod(TArray<FModioInstalledMod> &installed_mods);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetModDownloadQueue(TArray<FModioQueuedModDownload> &queued_mods);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioInstallDownloadedMods();

  // Browsing

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioGetAllMods(TEnumAsByte<EModioFilterType> filter_type, int32 limit, int32 offset);

  // Mod creation and uploads

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioAddMod(FModioModCreator mod_creator);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioEditMod(int32 mod_id, FModioModEditor mod_editor);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioAddModfile(int32 mod_id, FModioModfileCreator modfile_creator);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetModfileUploadQueue(TArray<FModioQueuedModfileUpload> &upload_queue);

  // Me

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioGetUserSubscriptions();

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioGetAuthenticatedUser();
};