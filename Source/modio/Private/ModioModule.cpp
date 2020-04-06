// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioModule.h"
#include "ModioSubsystem.h"
#include "../ModioPublic.h"
#include "ModioSettings.h"
#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsContainer.h"
#include "ISettingsSection.h"
#endif

#include "c/ModioC.h"
#include "Engine/Engine.h"
#include "Interfaces/IPluginManager.h"
// Declare module name on one place so we don't have to retype it if we rename the module
#define MODULE_NAME Modio
#define Q(x) #x
#define QUOTE(x) Q(x)
static FName ModuleName( QUOTE(MODULE_NAME) );
#undef QUOTE
#undef Q

IMPLEMENT_MODULE(FModioModule, modio)
// @todo: use MODULE_NAME again, functionality broke on v4.23.3
// IMPLEMENT_MODULE(FModioModule, MODULE_NAME)

DEFINE_LOG_CATEGORY(LogModio);

#define LOCTEXT_NAMESPACE "FModioModule"

FModioSubsystemPtr FModioSubsystem::Get( UWorld *world )
{
  FModioModule* module = FModuleManager::GetModulePtr<FModioModule>( ModuleName );
  if( module )
  {
    return module->GetModioImp( world );
  }
  return nullptr;
}

enum class EInstanceType : uint8
{
  Server,
  Client
};

/** Helper function to find the first instance of the instance type */
static bool IsLowestInstanceOf(UWorld *World, EInstanceType InstanceType)
{
  check(World);
    
  int LowestPIEInstance = INT_MAX;
  const TIndirectArray<FWorldContext>& AllWorldContexts = GEngine->GetWorldContexts();
  for (const FWorldContext& ContextItr : AllWorldContexts)
  {
    if (ContextItr.World()->GetNetMode() == NM_Client && InstanceType != EInstanceType::Client)
    {
      continue;
    }
    else if (ContextItr.World()->GetNetMode() != NM_Client && InstanceType != EInstanceType::Server)
    {
      continue;
    }
    LowestPIEInstance = FMath::Min(LowestPIEInstance, ContextItr.PIEInstance);
  }

  FWorldContext *WorldContext = GEngine->GetWorldContextFromWorld(World);
  if (WorldContext)
  {
    return WorldContext->PIEInstance == LowestPIEInstance;
  }
  return false;
}

FModioSubsystemPtr FModioModule::GetModioImp(UWorld *World) const
{
  return ModioImp;
}

void FModioModule::StartupModule()
{
  FString DllPath = IPluginManager::Get().FindPlugin("Modio")->GetBaseDir();
  DllPath.Append("/Source/ThirdParty/mod.io-sdk/bin/win64/modio.dll");
  DLLHandle = FPlatformProcess::GetDllHandle(*DllPath);
  
  const UModioSettings *Settings = GetDefault<UModioSettings>();
  ModioImp = FModioSubsystem::Create(Settings->RootDirectory, Settings->bRootDirectoryIsInUserSettingsDirectory, Settings->GameId, Settings->ApiKey, Settings->bIsLiveEnvironment, Settings->bInstallOnModDownload, Settings->bRetrieveModsFromOtherGames, Settings->bEnablePolling);

  // Need GIsEdtor check as this might run when running the game but not with the editor
  if (GIsEditor)
  {
    RegisterSettings();
  }
}

void FModioModule::ShutdownModule()
{
  // Need GIsEdtor check as this might run when running the game but not with the editor	
  if (UObjectInitialized() && GIsEditor)
  {
    UnregisterSettings();
  }

  if (ModioImp.IsValid())
  {
    ModioImp->Shutdown();
    ModioImp = nullptr;
  }
  
  if (DLLHandle != NULL)
  {
    FPlatformProcess::FreeDllHandle(DLLHandle);
  }
}

bool FModioModule::SupportsDynamicReloading()
{
  return true;
}

bool FModioModule::HandleSettingsSaved()
{
  FModioSubsystemPtr Modio = GetModioImp(GWorld);
  if( Modio.IsValid() )
  {
    Modio->Shutdown();
    Modio = nullptr;
  }

  UModioSettings *Settings = GetMutableDefault<UModioSettings>();

  // @todo: See if any setting is invalid, if so, set it to a valid setting and resave
  bool bResaveSettings = false;

  if (bResaveSettings)
  {
    Settings->SaveConfig();
  }

  ModioImp = FModioSubsystem::Create(Settings->RootDirectory, Settings->bRootDirectoryIsInUserSettingsDirectory, Settings->GameId, Settings->ApiKey, Settings->bIsLiveEnvironment, Settings->bInstallOnModDownload, Settings->bRetrieveModsFromOtherGames, Settings->bEnablePolling);

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
