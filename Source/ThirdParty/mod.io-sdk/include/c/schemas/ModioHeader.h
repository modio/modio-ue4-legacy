#ifndef MODIO_MODIOHEADER_H
#define MODIO_MODIOHEADER_H

#include "../ModioC.h"                     // for ModioHeader
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Header.h"

extern "C"
{
  void modioInitHeader(ModioHeader* header, nlohmann::json header_json);
  void modioInitHeaderCpp(ModioHeader* modio_header, modio::Header* Header);
  void modioFreeHeader(ModioHeader* header);
}

#endif
