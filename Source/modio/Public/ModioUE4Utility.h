// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/FModioMod.h"
#include "Enums/EModioFilterType.h"
#include "Customizables/FModioModCreator.h"
#include "Customizables/FModioModEditor.h"
#include "Customizables/FModioModfileCreator.h"

extern TArray<FModioMod> ConvertToTArrayMods(ModioMod* modio_mods, u32 mods_size);
extern void SetupModioFilterCreator(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset, ModioFilterCreator& modio_filter_creator);
extern void SetupModioModCreator(FModioModCreator ModCreator, ModioModCreator& modio_mod_creator);
extern void SetupModioModEditor(FModioModEditor ModEditor, ModioModEditor& modio_mod_editor);
extern void SetupModioModfileCreator(FModioModfileCreator ModfileCreator, ModioModfileCreator& modio_modfile_creator);