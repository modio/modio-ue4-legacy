#ifndef MODIO_MODIORATINGSUMMARY_H
#define MODIO_MODIORATINGSUMMARY_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"
;
using json = nlohmann::json;

extern "C"
{
  void modioInitRatingSummary(ModioRatingSummary* ratings, json ratings_json);
  void modioFreeRatingSummary(ModioRatingSummary* ratings);
}

#endif
