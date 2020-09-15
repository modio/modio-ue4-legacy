// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FmodioEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();
	
private:
  /** Returns true if the login button is enabled */
  static bool Enabled_LoginButton();

  /** Returns true if the login button is enabled */
  static bool Enabled_LogoutButton();

  void MapCommands();
	void AddToolbarExtension(FToolBarBuilder& Builder);
private:
	TSharedPtr<class FUICommandList> PluginCommands;
  
};
