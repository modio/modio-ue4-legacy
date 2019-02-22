// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioUE4Utility.h"

FModioUser user;

TArray<FModioMod> toTArrayMods(ModioMod* modio_mods, u32 mods_size)
{
  TArray<FModioMod> mods;
  for (u32 i = 0; i < mods_size; i++)
  {
    FModioMod mod;
    InitializeMod(mod, modio_mods[i]);
    mods.Add(mod);
  }
  return mods;
}

void setupModioFilterCreator(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset, ModioFilterCreator& modio_filter_creator)
{
  modioSetFilterLimit(&modio_filter_creator, (u32)Limit);
  modioSetFilterOffset(&modio_filter_creator, (u32)Offset);

  switch (FilterType)
  {
  case EModioFilterType::SORT_BY_ID:
    break;
  case EModioFilterType::SORT_BY_RATING:
    modioSetFilterSort(&modio_filter_creator, (char *)"rating", false);
    break;
  case EModioFilterType::SORT_BY_DATE_LIVE:
    modioSetFilterSort(&modio_filter_creator, (char *)"date_live", false);
    break;
  case EModioFilterType::SORT_BY_DATE_UPDATED:
    modioSetFilterSort(&modio_filter_creator, (char *)"date_updated", false);
    break;
  default:
    // @todo: handle error
    break;
  }
}

void setupModioModCreator(FModioModCreator ModCreator, ModioModCreator& modio_mod_creator)
{
  modioSetModCreatorMaturityOption(&modio_mod_creator, (u32)ModCreator.MaturityOption);
  modioSetModCreatorVisible(&modio_mod_creator, ModCreator.Visible);
  if (ModCreator.LogoPath != "")
    modioSetModCreatorLogoPath(&modio_mod_creator, TCHAR_TO_UTF8(*ModCreator.LogoPath));
  if (ModCreator.Name != "")
    modioSetModCreatorName(&modio_mod_creator, TCHAR_TO_UTF8(*ModCreator.Name));
  if (ModCreator.NameId != "")
    modioSetModCreatorNameid(&modio_mod_creator, TCHAR_TO_UTF8(*ModCreator.NameId));
  if (ModCreator.Summary != "")
    modioSetModCreatorSummary(&modio_mod_creator, TCHAR_TO_UTF8(*ModCreator.Summary));
  if (ModCreator.Description != "")
    modioSetModCreatorDescription(&modio_mod_creator, TCHAR_TO_UTF8(*ModCreator.Description));
  if (ModCreator.HomepageUrl != "")
    modioSetModCreatorHomepageURL(&modio_mod_creator, TCHAR_TO_UTF8(*ModCreator.HomepageUrl));
}

void setupModioModEditor(FModioModEditor ModEditor, ModioModEditor& modio_mod_editor)
{
  // @todo handle maturity option and visibility edition
  //modioSetModEditorMaturityOption(&modio_mod_editor, (u32)ModCreator.MaturityOption);
  //modioSetModCreatorVisible(&modio_mod_editor, ModCreator.Visible);
  if (ModEditor.Name != "")
    modioSetModEditorName(&modio_mod_editor, TCHAR_TO_UTF8(*ModEditor.Name));
  if (ModEditor.NameId != "")
    modioSetModEditorNameid(&modio_mod_editor, TCHAR_TO_UTF8(*ModEditor.NameId));
  if (ModEditor.Summary != "")
    modioSetModEditorSummary(&modio_mod_editor, TCHAR_TO_UTF8(*ModEditor.Summary));
  if (ModEditor.Description != "")
    modioSetModEditorDescription(&modio_mod_editor, TCHAR_TO_UTF8(*ModEditor.Description));
  if (ModEditor.HomepageUrl != "")
    modioSetModEditorHomepageURL(&modio_mod_editor, TCHAR_TO_UTF8(*ModEditor.HomepageUrl));
}