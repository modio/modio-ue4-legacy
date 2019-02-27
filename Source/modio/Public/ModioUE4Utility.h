// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"

// @todo Find a workaround to no treat the bitmasked unidefined option as a numeric constant
extern UNDEFINED_MATURITY_OPTION = 16;

extern TArray<FModioMod> ConvertToTArrayMods(ModioMod* modio_mods, u32 mods_size);
extern void SetupModioFilterCreator(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset, ModioFilterCreator& modio_filter_creator);
extern void SetupModioModCreator(FModioModCreator ModCreator, ModioModCreator& modio_mod_creator);
extern void SetupModioModEditor(FModioModEditor ModEditor, ModioModEditor& modio_mod_editor);
extern void SetupModioModfileCreator(FModioModfileCreator ModfileCreator, ModioModfileCreator& modio_modfile_creator);