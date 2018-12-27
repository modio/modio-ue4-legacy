#ifndef MODIO_MODIOHEADER_H
#define MODIO_MODIOHEADER_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitHeader(ModioHeader* header, nlohmann::json header_json);
  void modioFreeHeader(ModioHeader* header);
}

#endif
