#ifndef MODIO_MODIORESPONSE_H
#define MODIO_MODIORESPONSE_H

#include "../ModioC.h"                     // for ModioResponse
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Response.h"

extern "C"
{
  void modioInitResponse(ModioResponse* response, nlohmann::json response_json);
  void modioInitResponseCpp(ModioResponse* modio_response, modio::Response* response);
  void modioFreeResponse(ModioResponse* response);
}

#endif
