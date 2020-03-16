#ifndef MODIO_MODIOMOD_H
#define MODIO_MODIOMOD_H

#include "../ModioC.h"                     // for ModioMod
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Mod.h"  // for modioInitMod ...

extern "C"
{
  void modioInitMod(ModioMod* mod, nlohmann::json mod_json);
  void modioInitModCpp(ModioMod* mod, modio::Mod* mod_json);
  void modioFreeMod(ModioMod* mod);
}

#endif
