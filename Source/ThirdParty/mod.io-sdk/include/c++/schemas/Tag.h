#ifndef MODIO_TAG_H
#define MODIO_TAG_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioTag

namespace modio
{
class Tag
{
public:
  u32 date_added;
  std::string name;

  void initialize(ModioTag tag);
};

extern nlohmann::json toJson(Tag &tag);
} // namespace modio

#endif
