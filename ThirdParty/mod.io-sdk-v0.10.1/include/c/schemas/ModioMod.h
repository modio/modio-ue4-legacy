#ifndef MODIO_MODIOMOD_H
#define MODIO_MODIOMOD_H

#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioLogo.h"
#include "ModioUser.h"
#include "ModioMedia.h"
#include "ModioModfile.h"
#include "ModioStats.h"
#include "ModioTag.h"
#include "ModioMetadataKVP.h"

extern "C"
{
  void modioInitMod(ModioMod* mod, nlohmann::json mod_json);
  void modioFreeMod(ModioMod* mod);
}

#endif
