#ifndef MODIO_MODIOERROR_H
#define MODIO_MODIOERROR_H

#include "../ModioC.h"                     // for ModioError
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitError(ModioError* error, nlohmann::json image_json);
  void modioFreeError(ModioError* error);
}

#endif
