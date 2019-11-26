#ifndef MODIO_MODIOSTATS_H
#define MODIO_MODIOSTATS_H

#include "../ModioC.h"                     // for ModioStats
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitStats(ModioStats* stats, nlohmann::json stats_json);
  void modioFreeStats(ModioStats* stats);
}

#endif
