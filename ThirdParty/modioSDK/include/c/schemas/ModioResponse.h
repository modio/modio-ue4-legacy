#ifndef MODIO_MODIORESPONSE_H
#define MODIO_MODIORESPONSE_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioError.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitResponse(ModioResponse* response, json response_json);
  void modioFreeResponse(ModioResponse* response);
}

#endif
