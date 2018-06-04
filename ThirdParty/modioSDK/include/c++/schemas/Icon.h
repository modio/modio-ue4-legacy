#ifndef MODIO_ICON_H
#define MODIO_ICON_H

#include "../../c/schemas/ModioIcon.h"
#include "../../Globals.h"
#include "../../Utility.h"

namespace modio
{
  class Icon
  {
  public:
    std::string filename;
    std::string original;
    std::string thumb_64x64;
    std::string thumb_128x128;
    std::string thumb_256x256;
    int x;

    void initialize(ModioIcon Icon);
    json toJson();
  };
}

#endif
