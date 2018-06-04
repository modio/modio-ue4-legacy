#ifndef MODIO_MODIOMETADATAKVP_H
#define MODIO_MODIOMETADATAKVP_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitMetadataKVP(ModioMetadataKVP* metadata_kvp, json metadata_kvp_json);
  void modioFreeMetadataKVP(ModioMetadataKVP* metadata_kvp);
}

#endif
