#ifndef MODIO_MODIOERROR_H
#define MODIO_MODIOERROR_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitError(ModioError* error, json image_json);
  void modioFreeError(ModioError* error);
}

#endif
