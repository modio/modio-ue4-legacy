#ifndef MODIO_MODIOIMAGE_H
#define MODIO_MODIOIMAGE_H

#include "../ModioC.h"                     // for ModioImage
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitImage(ModioImage* image, nlohmann::json image_json);
  void modioFreeImage(ModioImage* image);
}

#endif
