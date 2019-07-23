#ifndef MODIO_MODIORESPONSE_H
#define MODIO_MODIORESPONSE_H

#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioError.h"

extern "C"
{
  void modioInitResponse(ModioResponse* response, nlohmann::json response_json);
  void modioFreeResponse(ModioResponse* response);
}

#endif
