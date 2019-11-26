#ifndef MODIO_MODIORATING_H
#define MODIO_MODIORATING_H

#include "../ModioC.h"                     // for ModioRating
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitRating(ModioRating* rating, nlohmann::json rating_json);
  void modioFreeRating(ModioRating* rating);
}

#endif
