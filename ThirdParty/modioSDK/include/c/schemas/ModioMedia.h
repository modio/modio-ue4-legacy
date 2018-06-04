#ifndef MODIO_MODIOMEDIA_H
#define MODIO_MODIOMEDIA_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioImage.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitMedia(ModioMedia* media, json media_json);
  void modioFreeMedia(ModioMedia* media);
}

#endif
