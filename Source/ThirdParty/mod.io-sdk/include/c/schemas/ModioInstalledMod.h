#ifndef MODIO_MODIOINSTALLEDMOD_H
#define MODIO_MODIOINSTALLEDMOD_H

#include "../ModioC.h"                     // for ModioInstalledMod
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
	void modioInitInstalledMod(ModioInstalledMod* installed_mod, nlohmann::json image_json);
}

#endif
