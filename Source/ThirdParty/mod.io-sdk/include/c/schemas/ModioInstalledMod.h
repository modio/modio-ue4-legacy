#ifndef MODIO_MODIOINSTALLEDMOD_H
#define MODIO_MODIOINSTALLEDMOD_H

#include "../ModioC.h"                     // for ModioInstalledMod
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/InstalledMod.h"

extern "C"
{
	void modioInitInstalledMod(ModioInstalledMod* installed_mod, nlohmann::json image_json);
	void modioInitInstalledModCpp(ModioInstalledMod* modio_installed_mod, modio::InstalledMod* installed_mod);
}

#endif
