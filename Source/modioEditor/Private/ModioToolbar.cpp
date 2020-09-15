// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "ModioToolbar.h"
#include "modioEditorCommands.h"
#include "Framework/MultiBox/MultiBoxDefs.h"
#include "Framework/MultiBox/MultiBoxExtender.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"

TSharedRef< SWidget > FModioToolbar::GenerateModioDropdown( TSharedRef<FUICommandList> InCommandList )
{
  FMenuBuilder MenuBuilder( true, InCommandList );
  MenuBuilder.AddMenuEntry( FmodioEditorCommands::Get().Login );
  MenuBuilder.AddMenuEntry( FmodioEditorCommands::Get().NewModWizard );
  MenuBuilder.AddMenuEntry( FmodioEditorCommands::Get().UploadMod );
  MenuBuilder.AddMenuEntry( FmodioEditorCommands::Get().Settings );
  return MenuBuilder.MakeWidget();
}