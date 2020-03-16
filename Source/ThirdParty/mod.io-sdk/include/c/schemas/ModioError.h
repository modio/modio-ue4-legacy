#ifndef MODIO_MODIOERROR_H
#define MODIO_MODIOERROR_H

#include "../ModioC.h"                     // for ModioError
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Error.h"

extern "C"
{
  void modioInitError(ModioError* error, nlohmann::json image_json);
  void modioInitErrorCpp(ModioError* modio_error, modio::Error* error);
  void modioFreeError(ModioError* error);
}

#endif
