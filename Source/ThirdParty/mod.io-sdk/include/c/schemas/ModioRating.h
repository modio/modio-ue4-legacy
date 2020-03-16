#ifndef MODIO_MODIORATING_H
#define MODIO_MODIORATING_H

#include "../ModioC.h"                     // for ModioRating
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Rating.h"

extern "C"
{
  void modioInitRating(ModioRating* rating, nlohmann::json rating_json);
  void modioInitRatingCpp(ModioRating* modio_rating, modio::Rating* rating);
  void modioFreeRating(ModioRating* rating);
}

#endif
