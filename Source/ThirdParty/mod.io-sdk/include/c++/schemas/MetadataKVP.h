#ifndef MODIO_METADATAKVP_H
#define MODIO_METADATAKVP_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for MetadataKVP

namespace modio
{
class MetadataKVP
{
public:
  std::string metakey;
  std::string metavalue;

  void initialize(ModioMetadataKVP metadata_kvp);
};

extern nlohmann::json toJson(MetadataKVP &metadata_kvp);
} // namespace modio

#endif
