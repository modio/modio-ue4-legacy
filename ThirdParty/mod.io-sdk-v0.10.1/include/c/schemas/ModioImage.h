#ifndef MODIO_MODIOIMAGE_H
#define MODIO_MODIOIMAGE_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitImage(ModioImage* image, nlohmann::json image_json);
  void modioFreeImage(ModioImage* image);
}

#endif
