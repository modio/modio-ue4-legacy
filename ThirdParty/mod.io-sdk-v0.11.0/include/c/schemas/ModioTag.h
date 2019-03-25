#ifndef MODIO_MODIOTAG_H
#define MODIO_MODIOTAG_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitTag(ModioTag* tag, nlohmann::json tag_json);
  void modioFreeTag(ModioTag* tag);
}

#endif
