#ifndef MODIO_MODIOMEDIA_H
#define MODIO_MODIOMEDIA_H

#include "../ModioC.h"                     // for ModioMedia
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitMedia(ModioMedia* media, nlohmann::json media_json);
  void modioFreeMedia(ModioMedia* media);
}

#endif
