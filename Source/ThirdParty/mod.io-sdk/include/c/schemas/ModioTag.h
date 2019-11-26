#ifndef MODIO_MODIOTAG_H
#define MODIO_MODIOTAG_H

#include "../ModioC.h"                     // for ModioTag
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitTag(ModioTag* tag, nlohmann::json tag_json);
  void modioFreeTag(ModioTag* tag);
}

#endif
