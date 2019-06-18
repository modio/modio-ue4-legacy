#ifndef MODIO_RATING_H
#define MODIO_RATING_H

#include "../../Globals.h"
#include "../../c/schemas/ModioRating.h"

namespace modio
{
class Rating
{
public:
  u32 game_id;
  u32 mod_id;
  u32 rating;
  u32 date_added;

  void initialize(ModioRating rating);
};

extern nlohmann::json toJson(Rating &rating);
} // namespace modio

#endif
