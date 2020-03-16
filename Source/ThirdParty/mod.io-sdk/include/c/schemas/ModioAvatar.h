#ifndef MODIO_MODIOAVATAR_H
#define MODIO_MODIOAVATAR_H

#include "../ModioC.h"                     // for ModioAvatar
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Avatar.h"

extern "C"
{
  void modioInitAvatar(ModioAvatar* avatar, nlohmann::json avatar_json);
  void modioInitAvatarCpp(ModioAvatar* modio_avatar, modio::Avatar* avatar);
  void modioFreeAvatar(ModioAvatar* avatar);
}

#endif
