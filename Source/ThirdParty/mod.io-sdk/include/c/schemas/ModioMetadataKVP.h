#ifndef MODIO_MODIOMETADATAKVP_H
#define MODIO_MODIOMETADATAKVP_H

#include "../ModioC.h"                     // for ModioMetadataKVP
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitMetadataKVP(ModioMetadataKVP* metadata_kvp, nlohmann::json metadata_kvp_json);
  void modioFreeMetadataKVP(ModioMetadataKVP* metadata_kvp);
}

#endif
