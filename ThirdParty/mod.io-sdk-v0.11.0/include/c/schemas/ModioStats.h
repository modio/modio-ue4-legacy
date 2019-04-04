#ifndef MODIO_MODIOSTATS_H
#define MODIO_MODIOSTATS_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitStats(ModioStats* stats, nlohmann::json stats_json);
  void modioFreeStats(ModioStats* stats);
}

#endif