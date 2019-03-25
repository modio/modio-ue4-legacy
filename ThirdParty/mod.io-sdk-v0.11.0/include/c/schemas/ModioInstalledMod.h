#ifndef MODIO_MODIOINSTALLEDMOD_H
#define MODIO_MODIOINSTALLEDMOD_H

#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioMod.h"

extern "C"
{
	void modioInitInstalledMod(ModioInstalledMod* installed_mod, nlohmann::json image_json);
	void modioFreeInstalledMod(ModioInstalledMod* installed_mod);
}

#endif
