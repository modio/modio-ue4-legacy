#ifndef MODIO_MODIOICON_H
#define MODIO_MODIOICON_H

#include "../ModioC.h"                     // for ModioIcon
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitIcon(ModioIcon* icon, nlohmann::json icon_json);
  void modioFreeIcon(ModioIcon* icon);
}

#endif
