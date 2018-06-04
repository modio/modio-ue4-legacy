#ifndef MODIO_FILEHASH_H
#define MODIO_FILEHASH_H

#include "../../c/schemas/ModioFilehash.h"
#include "../../Globals.h"

namespace modio
{
  class Filehash
  {
  public:
    std::string md5;

    void initialize(ModioFilehash filehash);
    json toJson();
  };
}

#endif
