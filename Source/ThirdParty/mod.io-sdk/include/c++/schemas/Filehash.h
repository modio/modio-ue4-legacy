#ifndef MODIO_FILEHASH_H
#define MODIO_FILEHASH_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioFilehash

namespace modio
{
class Filehash
{
public:
  std::string md5;

  void initialize(ModioFilehash filehash);
};

extern nlohmann::json toJson(Filehash &filehash);
} // namespace modio

#endif
