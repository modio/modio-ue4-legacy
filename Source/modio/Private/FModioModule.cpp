// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "FModioModule.h"
#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsContainer.h"
#include "ISettingsSection.h"
#endif

#define LOCTEXT_NAMESPACE "FModioModule"

void FModioModule::StartupModule()
{
  const UModioSettings *Settings = GetDefault<UModioSettings>();

  FString game_directory = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());

  u32 environment;
  if (Settings->IsLiveEnvironment)
    environment = MODIO_ENVIRONMENT_LIVE;
  else
    environment = MODIO_ENVIRONMENT_TEST;
  
  if (Settings->RootDirectory != "")
    game_directory += Settings->RootDirectory;

  u32 game_id = Settings->GameId;
  FString api_key = Settings->ApiKey;

  modioInit(environment, game_id, TCHAR_TO_UTF8(*api_key), TCHAR_TO_UTF8(*game_directory));

  modioSetDownloadListener(&onModInstalled);
  modioSetUploadListener(&onAddModfile);

  // Need GIsEdtor check as this might run when running the game but not with the editor
  if( GIsEditor )
  {
    RegisterSettings();
  }
}

void FModioModule::ShutdownModule()
{
  // Need GIsEdtor check as this might run when running the game but not with the editor	
  if ( UObjectInitialized() && GIsEditor )
  {
    UnregisterSettings();
  }
}

bool FModioModule::SupportsDynamicReloading()
{
  return true;
}

bool FModioModule::HandleSettingsSaved()
{
  UModioSettings *Settings = GetMutableDefault<UModioSettings>();
  bool ResaveSettings = false;

  if (ResaveSettings)
  {
    Settings->SaveConfig();
  }

  return true;
}

// @todo: Move Register/Unregister Settings to editor module as they use editor only ISettingsModule
void FModioModule::RegisterSettings()
{
  #if WITH_EDITOR
  if (ISettingsModule *SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
  {
    ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

    SettingsContainer->DescribeCategory("mod.io settings",
                                        LOCTEXT("RuntimeWDCategoryName", "mod.io settings"),
                                        LOCTEXT("RuntimeWDCategoryDescription", "mod.io configuration settings"));

    ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "mod.io settings", "General",
                                                                           LOCTEXT("RuntimeGeneralSettingsName", "General"),
                                                                           LOCTEXT("RuntimeGeneralSettingsDescription", "Base configuration for our game module"),
                                                                           GetMutableDefault<UModioSettings>());

    if (SettingsSection.IsValid())
    {
      SettingsSection->OnModified().BindRaw(this, &FModioModule::HandleSettingsSaved);
    }
  }
  #endif
}

void FModioModule::UnregisterSettings()
{
  #if WITH_EDITOR
  if (ISettingsModule *SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
  {
    SettingsModule->UnregisterSettings("Project", "mod.io Settings", "General");
  }
  #endif
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FModioModule, modio)