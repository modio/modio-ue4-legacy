// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Runtime/Core/Public/Modules/ModuleManager.h"
#include "modio.h"
#include "ModioSchemas.h"
#include "ModioPluginComponent.h"

// Settings
#include "ModioGameSettings.h"
#include "Developer/Settings/Public/ISettingsModule.h"
#include "Developer/Settings/Public/ISettingsSection.h"
#include "Developer/Settings/Public/ISettingsContainer.h"

#include "modioModule.generated.h"

extern modio::Instance *modio_instance;
extern std::string current_user_username;

class FModioModule : public IModuleInterface
{
public:
  /** IModuleInterface implementation */
  virtual void StartupModule() override;
  virtual void ShutdownModule() override;
  virtual bool SupportsDynamicReloading() override;

private:
  bool HandleSettingsSaved();
  void RegisterSettings();
  void UnregisterSettings();
};

UCLASS()
class UModioBPFunctionLibrary : public UBlueprintFunctionLibrary
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

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioGetAuthenticatedUser(FString &username);

  // Downloads and installs

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetAllInstalledMod(TArray<FModioInstalledMod> &installed_mods);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetModDownloadQueue(TArray<FModioQueuedModDownload> &queued_mods);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioInstallDownloadedMods();

  // Browsing

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioGetAllMods(TEnumAsByte<ModioFilterEnum::Type> filter_type, int32 limit, int32 offset);

  // Mod creation and uploads

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioAddMod(FModioModCreator mod_creator);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioEditMod(int32 mod_id, FModioModEditor mod_editor);

  UFUNCTION(BlueprintCallable, Category = "mod.io")
  static void ModioAddModfile(int32 mod_id, FModioModfileCreator modfile_creator);

  UFUNCTION(BlueprintPure, Category = "mod.io")
  static void ModioGetModfileUploadQueue(TArray<FModioQueuedModfileUpload> &upload_queue);
};