#ifndef MODIO_MODIOFILEHASH_H
#define MODIO_MODIOFILEHASH_H

#include "../ModioC.h"                     // for ModioFilehash
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitFilehash(ModioFilehash* filehash, nlohmann::json filehash_json);
  void modioFreeFilehash(ModioFilehash* filehash);
}

#endif
