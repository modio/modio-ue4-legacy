#ifndef MODIO_MODIOMETADATAKVP_H
#define MODIO_MODIOMETADATAKVP_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitMetadataKVP(ModioMetadataKVP* metadata_kvp, nlohmann::json metadata_kvp_json);
  void modioFreeMetadataKVP(ModioMetadataKVP* metadata_kvp);
}

#endif
