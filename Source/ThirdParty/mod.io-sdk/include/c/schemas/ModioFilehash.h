#ifndef MODIO_MODIOFILEHASH_H
#define MODIO_MODIOFILEHASH_H

#include "../ModioC.h"                     // for ModioFilehash
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Filehash.h"

extern "C"
{
  void modioInitFilehash(ModioFilehash* filehash, nlohmann::json filehash_json);
  void modioInitFilehashCpp(ModioFilehash* modio_filehash, modio::Filehash* filehash);
  void modioFreeFilehash(ModioFilehash* filehash);
}

#endif
