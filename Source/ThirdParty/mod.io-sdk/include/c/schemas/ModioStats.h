#ifndef MODIO_MODIOSTATS_H
#define MODIO_MODIOSTATS_H

#include "../ModioC.h"                     // for ModioStats
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Stats.h"

extern "C"
{
  void modioInitStats(ModioStats* stats, nlohmann::json stats_json);
  void modioInitStatsCpp(ModioStats* modio_stats, modio::Stats* stats);
  void modioFreeStats(ModioStats* stats);
}

#endif
