#pragma once

#include "CoreMinimal.h"
#include "Widgets/SWidget.h"
#include "Framework/Commands/UICommandList.h"

struct FModioToolbar
{
  /**
  * Generates menu content for the quick settings combo button drop down menu
  *
  * @return	Menu content widget
  */
  static TSharedRef< SWidget > GenerateModioDropdown( TSharedRef<FUICommandList> InCommandList );
};