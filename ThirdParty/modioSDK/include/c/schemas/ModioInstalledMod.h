#ifndef MODIO_MODIOINSTALLEDMOD_H
#define MODIO_MODIOINSTALLEDMOD_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioMod.h"

using json = nlohmann::json;

extern "C"
{
	void modioInitInstalledMod(ModioInstalledMod* installed_mod, json image_json);
	void modioFreeInstalledMod(ModioInstalledMod* installed_mod);
}

#endif
