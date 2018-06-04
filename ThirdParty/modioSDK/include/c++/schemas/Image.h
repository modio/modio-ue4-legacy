#ifndef MODIO_IMAGE_H
#define MODIO_IMAGE_H

#include "../../c/schemas/ModioImage.h"
#include "../../Globals.h"
#include "../../Utility.h"

namespace modio
{
  class Image
  {
  public:
    std::string filename;
    std::string original;
    std::string thumb_320x180;

    void initialize(ModioImage image);
    json toJson();
  };
}

#endif
