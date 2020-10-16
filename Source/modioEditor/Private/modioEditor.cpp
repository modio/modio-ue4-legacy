// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "modioEditor.h"
#include "modioEditorStyle.h"
#include "modioEditorCommands.h"
#include "Misc/MessageDialog.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "ModioToolbar.h"
#include "ModioSubsystem.h"
#include "Engine/World.h"

#include "LevelEditor.h"

static const FName modioEditorTabName("modioEditor");

#define LOCTEXT_NAMESPACE "FmodioEditorModule"

void FmodioEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FmodioEditorStyle::Initialize();
	FmodioEditorStyle::ReloadTextures();

	FmodioEditorCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);
  MapCommands();
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		
	// Remove the dropdown for now, as it's not used and just comfuses people
	if(0)
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Content", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FmodioEditorModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}
}

void FmodioEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FmodioEditorStyle::Shutdown();

	FmodioEditorCommands::Unregister();
}

bool FmodioEditorModule::Enabled_LoginButton()
{
  if( FModioSubsystemPtr modio = FModioSubsystem::Get( GWorld ) )
  {
    return !modio->IsLoggedIn();    
  }
  return false;
}

bool FmodioEditorModule::Enabled_LogoutButton()
{
  if( FModioSubsystemPtr modio = FModioSubsystem::Get( GWorld ) )
  {
    return modio->IsLoggedIn();
  }
  return false;
}

static bool Disabled() { return false; }

void FmodioEditorModule::MapCommands()
{
  // We have disabled all the plugin commands as the button isn't there anymore
  if(0)
  {
    PluginCommands->MapAction(
      FmodioEditorCommands::Get().Login,
      FExecuteAction::CreateRaw(this, &FmodioEditorModule::PluginButtonClicked),
      FCanExecuteAction::CreateStatic( &FmodioEditorModule::Enabled_LoginButton ) );

    PluginCommands->MapAction(
      FmodioEditorCommands::Get().Logout,
      FExecuteAction::CreateRaw( this, &FmodioEditorModule::PluginButtonClicked ),
      FCanExecuteAction::CreateStatic( &FmodioEditorModule::Enabled_LogoutButton ) );

    PluginCommands->MapAction(
      FmodioEditorCommands::Get().UploadMod,
      FExecuteAction::CreateRaw( this, &FmodioEditorModule::PluginButtonClicked ),
      FCanExecuteAction::CreateStatic( &Disabled ) );

    PluginCommands->MapAction(
      FmodioEditorCommands::Get().NewModWizard,
      FExecuteAction::CreateRaw( this, &FmodioEditorModule::PluginButtonClicked ),
      FCanExecuteAction::CreateStatic( &Disabled ) );

    PluginCommands->MapAction(
      FmodioEditorCommands::Get().Settings,
      FExecuteAction::CreateRaw( this, &FmodioEditorModule::PluginButtonClicked ),
      FCanExecuteAction::CreateStatic( &Disabled ) );
    }
}

void FmodioEditorModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FmodioEditorModule::PluginButtonClicked()")),
							FText::FromString(TEXT("modioEditor.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FmodioEditorModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddComboButton(
    FUIAction(),
    FOnGetContent::CreateStatic( &FModioToolbar::GenerateModioDropdown, PluginCommands.ToSharedRef() ),
    LOCTEXT( "QuickModioMenu", "Modio" ),
    LOCTEXT( "QuickModioMenu_Tooltip", "Modio Actions" ),
    FSlateIcon( FmodioEditorStyle::GetStyleSetName(), "Modio.Icon" ),
    false,
    "QuickModioMenu"
  );
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FmodioEditorModule, modioEditor)