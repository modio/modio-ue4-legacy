#ifndef MODIO_MODIOAVATAR_H
#define MODIO_MODIOAVATAR_H

#include "../ModioC.h"                     // for ModioAvatar
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitAvatar(ModioAvatar* avatar, nlohmann::json avatar_json);
  void modioFreeAvatar(ModioAvatar* avatar);
}

#endif
