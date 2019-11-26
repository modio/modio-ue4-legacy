#ifndef MODIO_MODIOHEADER_H
#define MODIO_MODIOHEADER_H

#include "../ModioC.h"                     // for ModioHeader
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitHeader(ModioHeader* header, nlohmann::json header_json);
  void modioFreeHeader(ModioHeader* header);
}

#endif
