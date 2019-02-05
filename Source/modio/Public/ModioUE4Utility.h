// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "ModioHWrapper.h"
#include "ModioUE4Plugin.h"

extern FString current_user_username;
extern TArray<FModioMod> toTArrayMods(ModioMod* modio_mods, u32 mods_size);