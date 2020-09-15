// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioRating.h"

void InitializeRating(FModioRating &Rating, const ModioRating &modio_rating)
{
  Rating.GameId = modio_rating.game_id;
  Rating.ModId = modio_rating.mod_id;
  Rating.Rating = modio_rating.rating;
  Rating.DateAdded = modio_rating.date_added;
}