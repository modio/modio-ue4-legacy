#ifndef MODIO_MODIOFILEHASH_H
#define MODIO_MODIOFILEHASH_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitFilehash(ModioFilehash* filehash, nlohmann::json filehash_json);
  void modioFreeFilehash(ModioFilehash* filehash);
}

#endif
