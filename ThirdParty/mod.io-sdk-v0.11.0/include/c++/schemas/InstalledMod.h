#ifndef MODIO_INSTALLEDMOD_H
#define MODIO_INSTALLEDMOD_H

#include "../../Utility.h"
#include "../../Globals.h"
#include "../../c/schemas/ModioInstalledMod.h"
#include "Mod.h"

namespace modio
{
class InstalledMod
{
public:
	u32 mod_id;
	u32 modfile_id;
	u32 date_updated;
	std::string path;
	Mod mod;

	void initialize(ModioInstalledMod installed_mod);
};

extern nlohmann::json toJson(InstalledMod &installed_mod);
} // namespace modio

#endif
