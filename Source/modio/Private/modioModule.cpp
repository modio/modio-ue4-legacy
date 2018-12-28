// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "modioModule.h"
#include "Core.h"
#include "ModuleManager.h"
#include "IPluginManager.h"

#define LOCTEXT_NAMESPACE "FmodioModule"

modio::Instance *modio_instance;

void FmodioModule::StartupModule()
{
	modio_instance = new modio::Instance(MODIO_ENVIRONMENT_TEST, 7, "e91c01b8882f4affeddd56c96111977b");
	RegisterSettings();
}

void FmodioModule::ShutdownModule()
{
	if (UObjectInitialized())
	{
		UnregisterSettings();
	}
	delete modio_instance;
}

bool FmodioModule::SupportsDynamicReloading()
{
	return true;
}

UModioBPFunctionLibrary::UModioBPFunctionLibrary(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UModioBPFunctionLibrary::modioProcess()
{
	modio_instance->process();
}

void UModioBPFunctionLibrary::modioEmailRequest(FString email)
{
	modio_instance->emailRequest(std::string(TCHAR_TO_UTF8(*email)), [&](const modio::Response &response) {
		UModioPluginComponent::OnEmailRequestDelegate.Broadcast((int32)response.code);
	});
}

void UModioBPFunctionLibrary::modioEmailExchange(FString security_code)
{
	modio_instance->emailExchange(std::string(TCHAR_TO_UTF8(*security_code)), [&](const modio::Response &response) {
		UModioPluginComponent::OnEmailExchangeDelegate.Broadcast((int32)response.code);
	});
}

bool FmodioModule::HandleSettingsSaved()
{
	UModioGameSettings* Settings = GetMutableDefault<UModioGameSettings>();
	bool ResaveSettings = false;

	// You can put any validation code in here and resave the settings in case an invalid
	// value has been entered

	if (ResaveSettings)
	{
		Settings->SaveConfig();
	}

	return true;
}

void FmodioModule::RegisterSettings()
{
	// Registering some settings is just a matter of exposing the default UObject of
	// your desired class, feel free to add here all those settings you want to expose
	// to your LDs or artists.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		// Create the new category
		ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

		SettingsContainer->DescribeCategory("mod.io settings",
			LOCTEXT("RuntimeWDCategoryName", "mod.io settings"),
			LOCTEXT("RuntimeWDCategoryDescription", "mod.io configuration settings"));

		// Register the settings
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "mod.io settings", "General",
			LOCTEXT("RuntimeGeneralSettingsName", "General"),
			LOCTEXT("RuntimeGeneralSettingsDescription", "Base configuration for our game module"),
			GetMutableDefault<UModioGameSettings>()
			);

		// Register the save handler to your settings, you might want to use it to
		// validate those or just act to settings changes.
		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &FmodioModule::HandleSettingsSaved);
		}
	}
}

void FmodioModule::UnregisterSettings()
{
	// Ensure to unregister all of your registered settings here, hot-reload would
	// otherwise yield unexpected results.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "mod.io Settings", "General");
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FmodioModule, modio)