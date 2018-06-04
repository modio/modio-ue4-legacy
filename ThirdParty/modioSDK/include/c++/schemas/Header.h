#ifndef MODIO_HEADER_H
#define MODIO_HEADER_H

#include "../../c/schemas/ModioHeader.h"
#include "../../Globals.h"
#include "../../Utility.h"

namespace modio
{
  class Header
  {
  public:
    std::string filename;
    std::string original;

    void initialize(ModioHeader Header);
    json toJson();
  };
}

#endif
