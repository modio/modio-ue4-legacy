#pragma once

#include "modio.h"
#include "ModioSchemas.h"
//#include "ModioUE4Utility.generated.h"

extern TArray<FModioMod> toTArrayMods(const std::vector<modio::Mod> &modio_mods);