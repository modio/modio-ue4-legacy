#ifndef MODIO_MODIOICON_H
#define MODIO_MODIOICON_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitIcon(ModioIcon* icon, nlohmann::json icon_json);
  void modioFreeIcon(ModioIcon* icon);
}

#endif
