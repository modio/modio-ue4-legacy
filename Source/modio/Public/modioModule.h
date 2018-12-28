// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"
#include "modio.h"
#include "ModioPluginComponent.h"

// Settings
#include "ModioGameSettings.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ISettingsContainer.h"

#include "modioModule.generated.h"

extern modio::Instance *modio_instance;

class FmodioModule : public IModuleInterface
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
	static void modioProcess();

	UFUNCTION(BlueprintCallable, Category="mod.io")
	static void modioEmailRequest(FString email);

	UFUNCTION(BlueprintCallable, Category="mod.io")
	static void modioEmailExchange(FString security_code);
};