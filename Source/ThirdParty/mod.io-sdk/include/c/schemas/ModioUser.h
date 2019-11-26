#ifndef MODIO_MODIOUSER_H
#define MODIO_MODIOUSER_H

#include "../ModioC.h"                     // for ModioUser
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitUser(ModioUser* user, nlohmann::json user_json);
  void modioFreeUser(ModioUser* user);
}

#endif
