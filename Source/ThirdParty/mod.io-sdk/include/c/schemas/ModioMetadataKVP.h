#ifndef MODIO_MODIOMETADATAKVP_H
#define MODIO_MODIOMETADATAKVP_H

#include "../ModioC.h"                     // for ModioMetadataKVP
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/MetadataKVP.h"

extern "C"
{
  void modioInitMetadataKVP(ModioMetadataKVP* metadata_kvp, nlohmann::json metadata_kvp_json);
  void modioInitMetadataKVPCpp(ModioMetadataKVP* modio_metadata_kvp, modio::MetadataKVP* metadata_kvp);
  void modioFreeMetadataKVP(ModioMetadataKVP* metadata_kvp);
}

#endif
