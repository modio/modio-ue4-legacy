#ifndef MODIO_RATINGSUMMARY_H
#define MODIO_RATINGSUMMARY_H

#include "../../Globals.h"
#include "../../c/schemas/ModioRatingSummary.h"

namespace modio
{
  class RatingSummary
  {
  public:
    u32 total_ratings;
    u32 positive_ratings;
    u32 negative_ratings;
    u32 percentage_positive;
    double weighted_aggregate;
    std::string display_text;

    void initialize(ModioRatingSummary ratings);
    json toJson();
  };
}

#endif
