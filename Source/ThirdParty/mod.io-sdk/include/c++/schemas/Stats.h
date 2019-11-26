#ifndef MODIO_MODSTATS_H
#define MODIO_MODSTATS_H

#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioStats

namespace modio
{
class Stats
{
public:
  u32 mod_id;
  u32 popularity_rank_position;
  u32 popularity_rank_total_mods;
  u32 downloads_total;
  u32 subscribers_total;
  u32 ratings_total;
  u32 ratings_positive;
  u32 ratings_negative;
  u32 ratings_percentage_positive;
  double ratings_weighted_aggregate;
  std::string ratings_display_text;
  u32 date_expires;

  void initialize(ModioStats mod);
};

extern nlohmann::json toJson(Stats &stats);
} // namespace modio

#endif
