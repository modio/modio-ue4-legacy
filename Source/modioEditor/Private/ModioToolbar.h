#pragma once

struct FModioToolbar
{
  /**
  * Generates menu content for the quick settings combo button drop down menu
  *
  * @return	Menu content widget
  */
  static TSharedRef< SWidget > GenerateModioDropdown( TSharedRef<FUICommandList> InCommandList );
};