#ifndef MODIO_MODIOMOD_H
#define MODIO_MODIOMOD_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioLogo.h"
#include "ModioUser.h"
#include "ModioMedia.h"
#include "ModioModfile.h"
#include "ModioRatingSummary.h"
#include "ModioTag.h"
#include "ModioMetadataKVP.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitMod(ModioMod* mod, json mod_json);
  void modioFreeMod(ModioMod* mod);
}

#endif
