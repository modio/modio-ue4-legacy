#ifndef MODIO_LOGO_H
#define MODIO_LOGO_H

#include "../../c/schemas/ModioLogo.h"
#include "../../Globals.h"
#include "../../Utility.h"

namespace modio
{
  class Logo
  {
  public:
    std::string filename;
    std::string original;
    std::string thumb_320x180;
    std::string thumb_640x360;
    std::string thumb_1280x720;

    void initialize(ModioLogo Logo);
    json toJson();
  };
}

#endif
