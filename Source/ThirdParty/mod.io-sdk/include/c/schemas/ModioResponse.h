#ifndef MODIO_MODIORESPONSE_H
#define MODIO_MODIORESPONSE_H

#include "../ModioC.h"                     // for ModioResponse
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitResponse(ModioResponse* response, nlohmann::json response_json);
  void modioFreeResponse(ModioResponse* response);
}

#endif
