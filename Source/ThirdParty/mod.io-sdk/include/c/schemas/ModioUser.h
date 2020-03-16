#ifndef MODIO_MODIOUSER_H
#define MODIO_MODIOUSER_H

#include "../ModioC.h"                     // for ModioUser
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/User.h"

extern "C"
{
  void modioInitUser(ModioUser* user, nlohmann::json user_json);
  void modioInitUserCpp(ModioUser* modio_user, modio::User* user);
  void modioFreeUser(ModioUser* user);
}

#endif
