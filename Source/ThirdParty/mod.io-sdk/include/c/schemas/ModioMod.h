#ifndef MODIO_MODIOMOD_H
#define MODIO_MODIOMOD_H

#include "../ModioC.h"                     // for ModioMod
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitMod(ModioMod* mod, nlohmann::json mod_json);
  void modioFreeMod(ModioMod* mod);
}

#endif
