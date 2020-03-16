#ifndef MODIO_MODIOMEDIA_H
#define MODIO_MODIOMEDIA_H

#include "../ModioC.h"                     // for ModioMedia
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Media.h"

extern "C"
{
  void modioInitMedia(ModioMedia* media, nlohmann::json media_json);
  void modioInitMediaCpp(ModioMedia* modio_media, modio::Media* media);
  void modioFreeMedia(ModioMedia* media);
}

#endif
