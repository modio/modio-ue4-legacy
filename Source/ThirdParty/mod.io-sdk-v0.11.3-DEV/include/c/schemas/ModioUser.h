#ifndef MODIO_MODIOUSER_H
#define MODIO_MODIOUSER_H

#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioAvatar.h"

extern "C"
{
  void modioInitUser(ModioUser* user, nlohmann::json user_json);
  void modioFreeUser(ModioUser* user);
}

#endif
