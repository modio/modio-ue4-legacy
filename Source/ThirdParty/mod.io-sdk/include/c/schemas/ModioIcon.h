#ifndef MODIO_MODIOICON_H
#define MODIO_MODIOICON_H

#include "../ModioC.h"                     // for ModioIcon
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Icon.h"

extern "C"
{
  void modioInitIcon(ModioIcon* icon, nlohmann::json icon_json);
  void modioInitIconCpp(ModioIcon* modio_icon, modio::Icon* icon);
  void modioFreeIcon(ModioIcon* icon);
}

#endif
