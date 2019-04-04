// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "modioEditorCommands.h"

#define LOCTEXT_NAMESPACE "FmodioEditorModule"

void FmodioEditorCommands::RegisterCommands()
{
	UI_COMMAND(Login, "Login", "Login to modio (not implemented)", EUserInterfaceActionType::Button, FInputGesture());
  UI_COMMAND(Logout, "Logout", "Logout from modio (not implemented)", EUserInterfaceActionType::Button, FInputGesture() );
  UI_COMMAND(UploadMod, "Upload Mod", "Upload mod to modio (not implemented)", EUserInterfaceActionType::Button, FInputGesture() );
  UI_COMMAND(NewModWizard, "New mod wizard", "r u a wizzard? (not implemented)", EUserInterfaceActionType::Button, FInputGesture() );
  UI_COMMAND(Settings, "Settings", "Configure modio environment (not implemented)", EUserInterfaceActionType::Button, FInputGesture() );
}

#undef LOCTEXT_NAMESPACE
