// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/ModioMod.h"
#include "Schemas/ModioModDependency.h"
#include "Schemas/ModioModTag.h"
#include "Schemas/ModioRating.h"
#include "Schemas/ModioModEvent.h"
#include "Schemas/ModioUserEvent.h"
#include "Enums/ModioFilterType.h"
#include "Customizables/ModioModCreator.h"
#include "Customizables/ModioModEditor.h"
#include "Customizables/ModioModfileCreator.h"

extern TArray<FModioMod> ConvertToTArrayMods(ModioMod* ModioMods, u32 ModsSize);
extern TArray<FModioModfile> ConvertToTArrayModfiles(ModioModfile* ModioModfiles, u32 ModfilesSize);
extern TArray<FModioRating> ConvertToTArrayRatings(ModioRating* ModioRatings, u32 RatingsSize);
extern TArray<FModioModDependency> ConvertToTArrayModDependencies(ModioDependency* ModioDependencies, u32 ModDependenciesSize);
extern TArray<FModioModTag> ConvertToTArrayModTags(ModioTag* ModioTags, u32 ModTagsSize);
extern TArray<FModioMetadataKVP> ConvertToTArrayMetadataKVPs(ModioMetadataKVP* ModioMetadataKVPs, u32 ModioMetadatasSize);
extern TArray<FModioUserEvent> ConvertToTArrayUserEvents(ModioUserEvent* ModioUserEvents, u32 UserEventsSize);
extern TArray<FModioModEvent> ConvertToTArrayModEvents(ModioModEvent* ModioModEvents, u32 ModEventsSize);
extern void SetupModioFilterCreator(TEnumAsByte<EModioFilterType> FilterType, int32 Limit, int32 Offset, ModioFilterCreator& modio_filter_creator);
extern void SetupModioModCreator(FModioModCreator ModCreator, ModioModCreator& modio_mod_creator);
extern void SetupModioModEditor(FModioModEditor ModEditor, ModioModEditor& modio_mod_editor);
extern void SetupModioModfileCreator(FModioModfileCreator ModfileCreator, ModioModfileCreator& modio_modfile_creator);