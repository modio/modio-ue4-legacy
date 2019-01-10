// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Runtime/Core/Public/Modules/ModuleManager.h"
#include "modio.h"
#include "ModioPluginComponent.h"

// Settings
#include "ModioGameSettings.h"
#include "Developer/Settings/Public/ISettingsModule.h"
#include "Developer/Settings/Public/ISettingsSection.h"
#include "Developer/Settings/Public/ISettingsContainer.h"

#include "modioModule.generated.h"

extern modio::Instance *modio_instance;
extern std::string current_user_username;

USTRUCT(BlueprintType)
struct FModioInstalledMod
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
	FString Path;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
	int32 Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
	FString Summary;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
	FString Description;
};

USTRUCT(BlueprintType)
struct FModioQueuedModDownload
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
	FString Path;
	// TODO: change to int64 unsupported by ue4
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
	int32 CurrentProgress;
	// TODO: change to int64 unsupported by ue4
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
	int32 TotalSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
	int32 Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
	FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
	FString Summary;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "mod.io")
	FString Description;
};

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

	UFUNCTION(BlueprintCallable, Category="mod.io")
	static void ModioProcess();

	UFUNCTION(BlueprintCallable, Category="mod.io")
	static void ModioEmailRequest(FString email);

	UFUNCTION(BlueprintCallable, Category="mod.io")
	static void ModioEmailExchange(FString security_code);

	UFUNCTION(BlueprintPure, Category="mod.io")
	static void ModioGetAllInstalledMod(TArray<FModioInstalledMod>& installed_mods);

	UFUNCTION(BlueprintPure, Category="mod.io")
	static void ModioGetModDownloadQueue(TArray<FModioQueuedModDownload>& queued_mods);

	UFUNCTION(BlueprintCallable, Category="mod.io")
	static void ModioInstallDownloadedMods();

	UFUNCTION(BlueprintCallable, Category="mod.io")
	static void ModioLogout();

	UFUNCTION(BlueprintCallable, Category="mod.io")
	static void ModioIsLoggedIn(bool& is_logged_in);

	UFUNCTION(BlueprintCallable, Category="mod.io")
	static void ModioGetAuthenticatedUser(FString& username);
};