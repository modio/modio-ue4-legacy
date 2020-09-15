// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioStats.h"

void InitializeStats(FModioStats &Stats, const ModioStats &modio_stats)
{
  Stats.ModId = modio_stats.mod_id;
  Stats.PopularityRankPosition = modio_stats.popularity_rank_position;
  Stats.PopularityRankTotalMods = modio_stats.popularity_rank_total_mods;
  Stats.DownloadsTotal = modio_stats.downloads_total;
  Stats.SubscribersTotal = modio_stats.subscribers_total;
  Stats.RatingsTotal = modio_stats.ratings_total;
  Stats.RatingsPositive = modio_stats.ratings_positive;
  Stats.RatingsNegative = modio_stats.ratings_negative;
  Stats.RatingsPercentagePositive = modio_stats.ratings_percentage_positive;
  Stats.RatingsWeightedAggregate = modio_stats.ratings_weighted_aggregate;
  Stats.DateExpires = modio_stats.date_expires;
  Stats.RatingsDisplayText = UTF8_TO_TCHAR(modio_stats.ratings_display_text);
}