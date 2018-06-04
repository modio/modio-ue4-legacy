#ifndef MODIO_MODIOUSER_H
#define MODIO_MODIOUSER_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioAvatar.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitUser(ModioUser* user, json user_json);
  void modioFreeUser(ModioUser* user);
}

#endif
