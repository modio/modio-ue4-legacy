// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioUE4Utility.h"

TArray<FModioMod> ConvertToTArrayMods(ModioMod* ModioMods, u32 ModsSize)
{
  TArray<FModioMod> Mods;
  for (u32 i = 0; i < ModsSize; i++)
  {
    FModioMod Mod;
    InitializeMod(Mod, ModioMods[i]);
    Mods.Add(Mod);
  }
  return Mods;
}

TArray<FModioModfile> ConvertToTArrayModfiles(ModioModfile* ModioModfiles, u32 ModfilesSize)
{
  TArray<FModioModfile> Modfiles;
  for (u32 i = 0; i < ModfilesSize; i++)
  {
    FModioModfile Modfile;
    InitializeModfile(Modfile, ModioModfiles[i]);
    Modfiles.Add(Modfile);
  }
  return Modfiles;
}

TArray<FModioRating> ConvertToTArrayRatings(ModioRating* ModioRatings, u32 RatingsSize)
{
  TArray<FModioRating> Ratings;
  for (u32 i = 0; i < RatingsSize; i++)
  {
    FModioRating Rating;
    InitializeRating(Rating, ModioRatings[i]);
    Ratings.Add(Rating);
  }
  return Ratings;
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

TArray<FModioMetadataKVP> ConvertToTArrayMetadataKVP(ModioMetadataKVP* ModioMetadataKVP, u32 MetadataKVPize)
{
  TArray<FModioMetadataKVP> TArray_MetadataKVP;
  for (u32 i = 0; i < MetadataKVPize; i++)
  {
    FModioMetadataKVP MetadataKVP;
    InitializeMetadataKVP(MetadataKVP, ModioMetadataKVP[i]);
    TArray_MetadataKVP.Add(MetadataKVP);
  }
  return TArray_MetadataKVP;
}

TArray<FModioUserEvent> ConvertToTArrayUserEvents(ModioUserEvent* ModioUserEvents, u32 UserEventsSize)
{
  TArray<FModioUserEvent> UserEvents;
  for (u32 i = 0; i < UserEventsSize; i++)
  {
    FModioUserEvent UserEvent;
    InitializeUserEvent(UserEvent, ModioUserEvents[i]);
    UserEvents.Add(UserEvent);
  }
  return UserEvents;
}

TArray<FModioModEvent> ConvertToTArrayModEvents(ModioModEvent* ModioModEvents, u32 ModEventsSize)
{
  TArray<FModioModEvent> ModEvents;
  for (u32 i = 0; i < ModEventsSize; i++)
  {
    FModioModEvent ModEvent;
    InitializeModEvent(ModEvent, ModioModEvents[i]);
    ModEvents.Add(ModEvent);
  }
  return ModEvents;
}

TEnumAsByte<EModioModState> ConvertToModState(u32 ModioModState)
{
  switch (ModioModState)
  {
  case MODIO_MOD_UNDEFINED:
    return EModioModState::NOT_DEFINED;
  case MODIO_MOD_NOT_INSTALLED:
    return EModioModState::NOT_INSTALLED;
  case MODIO_MOD_QUEUED:
    return EModioModState::QUEUED;
  case MODIO_MOD_STARTING_DOWNLOAD:
    return EModioModState::STARTING_DOWNLOAD;
  case MODIO_MOD_DOWNLOADING:
    return EModioModState::DOWNLOADING;
  case MODIO_MOD_PAUSING:
    return EModioModState::PAUSING;
  case MODIO_MOD_PAUSED:
    return EModioModState::PAUSED;
  case MODIO_MOD_INSTALLED:
    return EModioModState::INSTALLED;
  case MODIO_PRIORITIZING_OTHER_DOWNLOAD:
    return EModioModState::PRIORITIZING_OTHER_DOWNLOAD;
  case MODIO_MOD_STARTING_UPLOAD:
    return EModioModState::STARTING_UPLOAD;
  case MODIO_MOD_UPLOADING:
    return EModioModState::UPLOADING;
  case MODIO_MOD_DOWNLOADED:
    return EModioModState::DOWNLOADED;
  default:
    // @todo: handle error
    break;
  }
  return EModioModState::NOT_DEFINED;
}

TEnumAsByte<EModioRatingType> ConvertToModRatingType(u32 ModioModRating)
{
  switch (ModioModRating)
  {
  case MODIO_RATING_NEGATIVE:
    return EModioRatingType::RATING_NEGATIVE;
  case MODIO_RATING_POSITIVE:
    return EModioRatingType::RATING_POSITIVE;
  default:
    // @todo: handle error
    break;
  }
  return EModioRatingType::RATING_NOT_DEFINED;
}

void SetupModioFilterPagination(int32 Limit, int32 Offset, ModioFilterCreator& modio_filter_creator)
{
  modioSetFilterLimit(&modio_filter_creator, (u32)Limit);
  modioSetFilterOffset(&modio_filter_creator, (u32)Offset);
}

void SetupModSortingFilter(TEnumAsByte<EModioModSortType> ModSortType, ModioFilterCreator& modio_filter_creator, bool IsAscending)
{
  switch (ModSortType)
  {
  case EModioModSortType::SORT_BY_ID:
    break;
  case EModioModSortType::SORT_BY_DATE_ADDED:
    modioSetFilterSort(&modio_filter_creator, (char *)"date_added", IsAscending);
    break;
  case EModioModSortType::SORT_BY_DATE_UPDATED:
    modioSetFilterSort(&modio_filter_creator, (char *)"date_updated", IsAscending);
    break;
  case EModioModSortType::SORT_BY_DATE_LIVE:
    modioSetFilterSort(&modio_filter_creator, (char *)"date_live", IsAscending);
    break;
  case EModioModSortType::SORT_BY_NAME:
    modioSetFilterSort(&modio_filter_creator, (char *)"name", IsAscending);
    break;
  case EModioModSortType::SORT_BY_DOWNLOADS:
    modioSetFilterSort(&modio_filter_creator, (char *)"downloads", IsAscending);
    break;
  case EModioModSortType::SORT_BY_POPULAR:
    modioSetFilterSort(&modio_filter_creator, (char *)"popular", IsAscending);
    break;
  case EModioModSortType::SORT_BY_RATING:
    modioSetFilterSort(&modio_filter_creator, (char *)"rating", IsAscending);
    break;
  case EModioModSortType::SORT_BY_SUBSCRIBERS:
    modioSetFilterSort(&modio_filter_creator, (char *)"subscribers", IsAscending);
    break;
  default:
    // @todo: handle error
    break;
  }
}

void SetupModioModFilterCreator(const FModioFilterCreator &FilterCreator, const TArray<FString> &ModTags, int32 Limit, int32 Offset, ModioFilterCreator& modio_filter_creator)
{
  modioSetFilterLimit(&modio_filter_creator, (u32)Limit);
  modioSetFilterOffset(&modio_filter_creator, (u32)Offset);

  for (int i = 0; i < ModTags.Num(); i++)
    modioAddFilterInField(&modio_filter_creator, "tags", TCHAR_TO_UTF8(*ModTags[i]) );

  bool IsAscending = FilterCreator.Sort.Ascending;
  SetupModSortingFilter(FilterCreator.Sort.ModSortType, modio_filter_creator, IsAscending);

  if(FilterCreator.FullTextSearch != "")
    modioSetFilterFullTextSearch(&modio_filter_creator, TCHAR_TO_UTF8(*FilterCreator.FullTextSearch));
  
  for (auto& FieldFilter : FilterCreator.FieldFilters)
  {
    switch (FieldFilter.Type)
    {
    case EModioFieldFilterType::FIELD_FILTER_EQUAL:
      modioAddFilterFieldValue(&modio_filter_creator, TCHAR_TO_UTF8(*FieldFilter.Field), TCHAR_TO_UTF8(*FieldFilter.Value) );
      break;
    case EModioFieldFilterType::FIELD_FILTER_NOT_EQUAL:
      modioAddFilterNotEqualField(&modio_filter_creator, TCHAR_TO_UTF8(*FieldFilter.Field), TCHAR_TO_UTF8(*FieldFilter.Value) );
      break;
    case EModioFieldFilterType::FIELD_FILTER_LIKE:
      modioAddFilterLikeField(&modio_filter_creator, TCHAR_TO_UTF8(*FieldFilter.Field), TCHAR_TO_UTF8(*FieldFilter.Value) );
      break;
    case EModioFieldFilterType::FIELD_FILTER_NOT_LIKE:
      modioAddFilterNotLikeField(&modio_filter_creator, TCHAR_TO_UTF8(*FieldFilter.Field), TCHAR_TO_UTF8(*FieldFilter.Value) );
      break;
    case EModioFieldFilterType::FIELD_FILTER_IN:
      modioAddFilterInField(&modio_filter_creator, TCHAR_TO_UTF8(*FieldFilter.Field), TCHAR_TO_UTF8(*FieldFilter.Value) );
      break;
    case EModioFieldFilterType::FIELD_FILTER_NOT_IN:
      modioAddFilterNotInField(&modio_filter_creator, TCHAR_TO_UTF8(*FieldFilter.Field), TCHAR_TO_UTF8(*FieldFilter.Value) );
      break;
    case EModioFieldFilterType::FIELD_FILTER_MIN:
      modioAddFilterMinField(&modio_filter_creator, TCHAR_TO_UTF8(*FieldFilter.Field), TCHAR_TO_UTF8(*FieldFilter.Value) );
      break;
    case EModioFieldFilterType::FIELD_FILTER_MAX:
      modioAddFilterMaxField(&modio_filter_creator, TCHAR_TO_UTF8(*FieldFilter.Field), TCHAR_TO_UTF8(*FieldFilter.Value) );
      break;
    case EModioFieldFilterType::FIELD_FILTER_SMALLER_THAN:
      modioAddFilterSmallerThanField(&modio_filter_creator, TCHAR_TO_UTF8(*FieldFilter.Field), TCHAR_TO_UTF8(*FieldFilter.Value) );
      break;
    case EModioFieldFilterType::FIELD_FILTER_GREATER_THAN:
      modioAddFilterGreaterThanField(&modio_filter_creator, TCHAR_TO_UTF8(*FieldFilter.Field), TCHAR_TO_UTF8(*FieldFilter.Value) );
      break;
    }
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

  for (int i = 0; i < ModCreator.Tags.Num(); i++) {
    modioAddModCreatorTag(&modio_mod_creator, TCHAR_TO_UTF8(*ModCreator.Tags[i]) );
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
  if (ModCreator.MetadataBlob != "")
	  modioSetModCreatorMetadataBlob(&modio_mod_creator, TCHAR_TO_UTF8(*ModCreator.MetadataBlob));
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
  if (ModEditor.MetadataBlob != "")
	  modioSetModEditorMetadataBlob(&modio_mod_editor, TCHAR_TO_UTF8(*ModEditor.MetadataBlob));
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
  {
    char* AnsiModfilePath = new char[ModfileCreator.Path.Len()];
    windowsUTF8ToAnsi(TCHAR_TO_UTF8(*ModfileCreator.Path), AnsiModfilePath);
    modioSetModfileCreatorPath(&modio_modfile_creator, AnsiModfilePath);
    delete[] AnsiModfilePath;
  }
  if (ModfileCreator.Version != "")
    modioSetModfileCreatorVersion(&modio_modfile_creator, TCHAR_TO_UTF8(*ModfileCreator.Version));
  if (ModfileCreator.Changelog != "")
    modioSetModfileCreatorChangelog(&modio_modfile_creator, TCHAR_TO_UTF8(*ModfileCreator.Changelog));
  if (ModfileCreator.Filehash != "")
    modioSetModfileCreatorFilehash(&modio_modfile_creator, TCHAR_TO_UTF8(*ModfileCreator.Filehash));
}

std::string toString(int32 number)
{
  if (number == 0)
    return "0";

  if (number < 0)
    return "-" + toString(-number);

  std::string temp = "";
  std::string returnvalue = "";
  while (number > 0)
  {
    temp += number % 10 + 48;
    number /= 10;
  }
  for (size_t i = 0; i < temp.length(); i++)
    returnvalue += temp[temp.length() - i - 1];
  return returnvalue;
}