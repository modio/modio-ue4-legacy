#ifndef MODIO_RATING_H
#define MODIO_RATING_H

#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioRating

namespace modio
{
class Rating
{
public:
  u32 game_id;
  u32 mod_id;
  i32 rating;
  u32 date_added;

  void initialize(ModioRating rating);
};

extern nlohmann::json toJson(Rating &rating);
} // namespace modio

#endif
