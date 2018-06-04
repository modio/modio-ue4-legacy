#ifndef MODIO_MODIOTAG_H
#define MODIO_MODIOTAG_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitTag(ModioTag* tag, json tag_json);
  void modioFreeTag(ModioTag* tag);
}

#endif
