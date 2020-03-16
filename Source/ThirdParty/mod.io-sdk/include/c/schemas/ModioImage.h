#ifndef MODIO_MODIOIMAGE_H
#define MODIO_MODIOIMAGE_H

#include "../ModioC.h"                     // for ModioImage
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Image.h"

extern "C"
{
  void modioInitImage(ModioImage* image, nlohmann::json image_json);
  void modioInitImageCpp(ModioImage* modio_image, modio::Image* image);
  void modioFreeImage(ModioImage* image);
}

#endif
