// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "modioModule.h"
#include "Core.h"
#include "ModuleManager.h"
#include "Runtime/Projects/Public/Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FModioModule"

modio::Instance *modio_instance;
std::string current_user_username;

void FModioModule::StartupModule()
{
  UModioGameSettings *Settings = GetMutableDefault<UModioGameSettings>();

  u32 environment;
  if (Settings->IsLiveEnvironment)
    environment = MODIO_ENVIRONMENT_LIVE;
  else
    environment = MODIO_ENVIRONMENT_TEST;
  u32 game_id = Settings->GameId;
  std::string api_key = std::string(TCHAR_TO_UTF8(*(Settings->ApiKey)));

  modio_instance = new modio::Instance(environment, game_id, api_key);

  modio_instance->setDownloadListener([&](u32 response_code, u32 mod_id) {
    UModioPluginComponent::OnModDownloadDelegate.Broadcast((int32)response_code);
  });

  current_user_username = "";

  modio_instance->getAuthenticatedUser([&](const modio::Response &response, const modio::User &user) {
    current_user_username = user.username;
  });

  RegisterSettings();
}

void FModioModule::ShutdownModule()
{
  if (UObjectInitialized())
  {
    UnregisterSettings();
  }
  delete modio_instance;
}

bool FModioModule::SupportsDynamicReloading()
{
  return true;
}

UModioBPFunctionLibrary::UModioBPFunctionLibrary(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UModioBPFunctionLibrary::ModioProcess()
{
  modio_instance->process();
}

void UModioBPFunctionLibrary::ModioEmailRequest(FString email)
{
  modio_instance->emailRequest(std::string(TCHAR_TO_UTF8(*email)), [&](const modio::Response &response) {
    UModioPluginComponent::OnEmailRequestDelegate.Broadcast((int32)response.code);
  });
}

void UModioBPFunctionLibrary::ModioEmailExchange(FString security_code)
{
  modio_instance->emailExchange(std::string(TCHAR_TO_UTF8(*security_code)), [&](const modio::Response &response) {
    modio_instance->getAuthenticatedUser([&](const modio::Response &response, const modio::User &user) {
      current_user_username = user.username;
    });

    UModioPluginComponent::OnEmailExchangeDelegate.Broadcast((int32)response.code);
  });
}

void UModioBPFunctionLibrary::ModioGetAllInstalledMod(TArray<FModioInstalledMod> &installed_mods)
{
  // use mod.io C++ wrapper instead of C
  const std::vector<modio::InstalledMod> modio_installed_mods = modio_instance->getAllInstalledMods();

  for (u32 i = 0; i < modio_installed_mods.size(); i++)
  {
    FModioInstalledMod installed_mod;
    installed_mod.Path = UTF8_TO_TCHAR(modio_installed_mods[i].path.c_str());
    installed_mod.Id = modio_installed_mods[i].mod.id;
    installed_mod.Name = UTF8_TO_TCHAR(modio_installed_mods[i].mod.name.c_str());
    installed_mod.Summary = UTF8_TO_TCHAR(modio_installed_mods[i].mod.summary.c_str());
    installed_mod.Description = UTF8_TO_TCHAR(modio_installed_mods[i].mod.description.c_str());
    installed_mods.Add(installed_mod);
  }
}

void UModioBPFunctionLibrary::ModioGetModDownloadQueue(TArray<FModioQueuedModDownload> &queued_mods)
{
  // use mod.io C++ wrapper instead of C
  u32 download_queue_count = modioGetModDownloadQueueCount();
  ModioQueuedModDownload *modio_queued_mods = (ModioQueuedModDownload *)malloc(download_queue_count * sizeof(*modio_queued_mods));
  modioGetModDownloadQueue(modio_queued_mods);

  for (u32 i = 0; i < download_queue_count; i++)
  {
    FModioQueuedModDownload queued_mod;
    queued_mod.Path = UTF8_TO_TCHAR(modio_queued_mods[i].path);
    queued_mod.CurrentProgress = modio_queued_mods[i].current_progress;
    queued_mod.TotalSize = modio_queued_mods[i].total_size;
    queued_mod.Id = modio_queued_mods[i].mod.id;
    queued_mod.Name = UTF8_TO_TCHAR(modio_queued_mods[i].mod.name);
    queued_mod.Summary = UTF8_TO_TCHAR(modio_queued_mods[i].mod.summary);
    queued_mod.Description = UTF8_TO_TCHAR(modio_queued_mods[i].mod.description);
    queued_mods.Add(queued_mod);
  }

  free(modio_queued_mods);
}

void UModioBPFunctionLibrary::ModioInstallDownloadedMods()
{
  modio_instance->installDownloadedMods();
}

void UModioBPFunctionLibrary::ModioLogout()
{
  modio_instance->logout();
}

void UModioBPFunctionLibrary::ModioIsLoggedIn(bool &is_logged_in)
{
  is_logged_in = modio_instance->isLoggedIn();
}

void UModioBPFunctionLibrary::ModioGetAuthenticatedUser(FString &username)
{
  username = UTF8_TO_TCHAR(current_user_username.c_str());
}

void UModioBPFunctionLibrary::ModioGetAllMods(TEnumAsByte<ModioFilterEnum::Type> filter_type, int32 limit, int32 offset)
{
  modio::FilterCreator filter_creator;
  filter_creator.setLimit((u32)limit);
  filter_creator.setOffset((u32)offset);

  modio_instance->getAllMods(filter_creator, [&](const modio::Response& response, const std::vector<modio::Mod> & modio_mods) {
    TArray<FModioMod> mods;
    for (u32 i = 0; i < modio_mods.size(); i++)
    {
      FModioMod mod;
      mod.Id = modio_mods[i].id;
      mod.Name = UTF8_TO_TCHAR(modio_mods[i].name.c_str());
      mod.Summary = UTF8_TO_TCHAR(modio_mods[i].summary.c_str());
      mod.Description = UTF8_TO_TCHAR(modio_mods[i].description.c_str());
      mods.Add(mod);
    }
    UModioPluginComponent::OnGetAllModsDelegate.Broadcast((int32)response.code, mods);
  });
}

bool FModioModule::HandleSettingsSaved()
{
  UModioGameSettings *Settings = GetMutableDefault<UModioGameSettings>();
  bool ResaveSettings = false;

  // You can put any validation code in here and resave the settings in case an invalid
  // value has been entered

  if (ResaveSettings)
  {
    Settings->SaveConfig();
  }

  return true;
}

void FModioModule::RegisterSettings()
{
  // Registering some settings is just a matter of exposing the default UObject of
  // your desired class, feel free to add here all those settings you want to expose
  // to your LDs or artists.

  if (ISettingsModule *SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
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
                                                                           GetMutableDefault<UModioGameSettings>());

    // Register the save handler to your settings, you might want to use it to
    // validate those or just act to settings changes.
    if (SettingsSection.IsValid())
    {
      SettingsSection->OnModified().BindRaw(this, &FModioModule::HandleSettingsSaved);
    }
  }
}

void FModioModule::UnregisterSettings()
{
  // Ensure to unregister all of your registered settings here, hot-reload would
  // otherwise yield unexpected results.

  if (ISettingsModule *SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
  {
    SettingsModule->UnregisterSettings("Project", "mod.io Settings", "General");
  }
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FModioModule, modio)