#ifndef MODIO_MODIOTAG_H
#define MODIO_MODIOTAG_H

#include "../ModioC.h"                     // for ModioTag
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Tag.h"

extern "C"
{
  void modioInitTag(ModioTag* tag, nlohmann::json tag_json);
  void modioInitTagCpp(ModioTag* modio_tag, modio::Tag* tag);
  void modioFreeTag(ModioTag* tag);
}

#endif
