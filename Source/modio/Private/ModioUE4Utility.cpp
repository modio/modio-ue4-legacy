// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioUE4Utility.h"

TArray<FModioMod> ConvertToTArrayMods(ModioMod* modio_mods, u32 mods_size)
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

TArray<FModioModDependency> ConvertToTArrayModDependencies(ModioDependency* ModioDependencies, u32 DependenciesSize)
{
  TArray<FModioModDependency> ModDependencies;
  for (u32 i = 0; i < DependenciesSize; i++)
  {
    FModioModDependency ModDependency;
    InitializeModDependency(ModDependency, ModioDependencies[i]);
    ModDependencies.Add(ModDependency);
  }
  return ModDependencies;
}

TArray<FModioModTag> ConvertToTArrayModTags(ModioTag* ModioTags, u32 TagsSize)
{
  TArray<FModioModTag> ModTags;
  for (u32 i = 0; i < TagsSize; i++)
  {
    FModioModTag ModTag;
    InitializeModTag(ModTag, ModioTags[i]);
    ModTags.Add(ModTag);
  }
  return ModTags;
}

void SetupModioFilterCreator(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset, ModioFilterCreator& modio_filter_creator)
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

void SetupModioModCreator(FModioModCreator ModCreator, ModioModCreator& modio_mod_creator)
{
  modioSetModCreatorMaturityOption(&modio_mod_creator, (u32)ModCreator.MaturityOption);

  switch (ModCreator.Visible)
  {
  case EModioBooleanCustomizableType::SET_TO_TRUE:
    modioSetModCreatorVisible(&modio_mod_creator, true);
    break;
  case EModioBooleanCustomizableType::SET_TO_FALSE:
    modioSetModCreatorVisible(&modio_mod_creator, false);
    break;
  }

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

void SetupModioModEditor(FModioModEditor ModEditor, ModioModEditor& modio_mod_editor)
{
  modioSetModEditorMaturityOption(&modio_mod_editor, (u32)ModEditor.MaturityOption);
  switch (ModEditor.Visible)
  {
  case EModioBooleanCustomizableType::SET_TO_TRUE:
    modioSetModEditorVisible(&modio_mod_editor, true);
    break;
  case EModioBooleanCustomizableType::SET_TO_FALSE:
    modioSetModEditorVisible(&modio_mod_editor, false);
    break;
  }

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

void SetupModioModfileCreator(FModioModfileCreator ModfileCreator, ModioModfileCreator& modio_modfile_creator)
{
  switch (ModfileCreator.Active)
  {
  case EModioBooleanCustomizableType::SET_TO_TRUE:
    modioSetModfileCreatorActive(&modio_modfile_creator, true);
    break;
  case EModioBooleanCustomizableType::SET_TO_FALSE:
    modioSetModfileCreatorActive(&modio_modfile_creator, false);
    break;
  }

  if (ModfileCreator.Path != "")
    modioSetModfileCreatorPath(&modio_modfile_creator, TCHAR_TO_UTF8(*ModfileCreator.Path));
  if (ModfileCreator.Version != "")
    modioSetModfileCreatorVersion(&modio_modfile_creator, TCHAR_TO_UTF8(*ModfileCreator.Version));
  if (ModfileCreator.Changelog != "")
    modioSetModfileCreatorChangelog(&modio_modfile_creator, TCHAR_TO_UTF8(*ModfileCreator.Changelog));
  if (ModfileCreator.Filehash != "")
    modioSetModfileCreatorFilehash(&modio_modfile_creator, TCHAR_TO_UTF8(*ModfileCreator.Filehash));
}