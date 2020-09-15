// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "modioEditorStyle.h"

class FmodioEditorCommands : public TCommands<FmodioEditorCommands>
{
public:

	FmodioEditorCommands()
		: TCommands<FmodioEditorCommands>(TEXT("modioEditor"), NSLOCTEXT("Contexts", "modioEditor", "modioEditor Plugin"), NAME_None, FmodioEditorStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > Login;
  TSharedPtr< FUICommandInfo > Logout;
  TSharedPtr< FUICommandInfo > UploadMod;
  TSharedPtr< FUICommandInfo > NewModWizard;
  TSharedPtr< FUICommandInfo > Settings;
};
