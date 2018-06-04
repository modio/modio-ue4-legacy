#ifndef MODIO_MODIOHEADER_H
#define MODIO_MODIOHEADER_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitHeader(ModioHeader* header, json header_json);
  void modioFreeHeader(ModioHeader* header);
}

#endif
