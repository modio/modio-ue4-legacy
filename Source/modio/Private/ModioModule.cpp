// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioModule.h"
#include "ModioSubsystem.h"
#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsContainer.h"
#include "ISettingsSection.h"
#endif

// Declare module name on one place so we don't have to retype it if we rename the module
#define MODULE_NAME modio
#define STRINGIFY(s) #s
static FName ModuleName( STRINGIFY(MODULE_NAME) );
#undef STRYINGIFY

IMPLEMENT_MODULE( FModioModule, MODULE_NAME )

DEFINE_LOG_CATEGORY( LogModio );

#define LOCTEXT_NAMESPACE "FModioModule"

FModioSubsystemPtr IModioModule::Get(UWorld* world)
{
  FModioModule* module = FModuleManager::GetModulePtr<FModioModule>( ModuleName );
  if( module )
  {
    module->GetModioImp(world);
  }
  return nullptr;  
}

FModioSubsystemPtr FModioModule::GetModioImp( UWorld* world )
{
  // Must pass in a valid word to get the interface, we don't default to GWorld
  // as some functions might actually pass in a null world by accident
  if( !IsValid( world ) )
  {
    return nullptr;
  }

  const UModioSettings *Settings = GetDefault<UModioSettings>();

  bool bIsDedicatedServerWorld = IsValid( world->GetGameInstance() ) ? world->GetGameInstance()->IsDedicatedServerInstance() : false;
  if( bIsDedicatedServerWorld && !Settings->bRunOnDedicatedServer )
  {
    return nullptr;
  }

// In final game, we don't need to care about editor, so we can strip out all these checks
#if WITH_EDITOR
  // @todo: Check if GIsEditor is set when running standalone game
  if( GIsEditor )
  {
    // Always return the implementation in editor, as then the developer is creating editor tools
    if( world->WorldType == EWorldType::Editor || world->WorldType == EWorldType::EditorPreview )
    {
      return ModioImp;
    }

    // If dedicated server world, make sure we should run on it
    if( bIsDedicatedServerWorld )
    {
      if( Settings->RunInEditor == ERunInEditorOn::DedicatedServer )
      {
        return ModioImp;
      }
      return nullptr;
    }
    
    if( world->IsGameWorld() )
    {
      // We don't want clients in PIE to have the world
      if( world->IsClient() )
      {
        #error Loop through these to find lowest world context
        // GEngine->GetWorldContexts 
        GEngine->GetWorldContextFromWorld( OwningWorld ))
        // 
        if( Settings->RunInEditor::FirstClient )
        {
          // @todo: I would like to loop through all worlds and find what their ID is, so we can take the lowest
          if( GPlayInEditorID == 1 )
          {
          }
        }
        return nullptr;
      }
      return ModioImp;
    }
  }
#endif

  // Else, if it's another game world that's not PIE, always return the implementation
  if( world->IsGameWorld() )
  {
    return ModioImp;    
  }

  return nullptr;
}

void FModioModule::StartupModule()
{
  ModioImp = MakeShared<FModioSubsystem, ESPMode::ThreadSafe>();
  ModioImp->Init();

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

  ModioImp->Shutdown();
  ModioImp.Reset();
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