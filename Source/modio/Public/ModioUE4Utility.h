// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioUE4Plugin.h"

extern TArray<FModioMod> toTArrayMods(ModioMod* modio_mods, u32 mods_size);
extern void setupModioFilterCreator(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset, ModioFilterCreator& modio_filter_creator);
extern void setupModioModCreator(FModioModCreator ModCreator, ModioModCreator& modio_mod_creator);
extern void setupModioModEditor(FModioModEditor ModEditor, ModioModEditor& modio_mod_editor);
extern void setupModioModfileCreator(FModioModfileCreator ModfileCreator, ModioModfileCreator& modio_modfile_creator);