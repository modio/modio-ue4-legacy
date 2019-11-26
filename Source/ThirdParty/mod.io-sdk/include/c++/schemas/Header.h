#ifndef MODIO_HEADER_H
#define MODIO_HEADER_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioHeader

namespace modio
{
class Header
{
public:
  std::string filename;
  std::string original;

  void initialize(ModioHeader Header);
};

extern nlohmann::json toJson(Header &header);
} // namespace modio

#endif
