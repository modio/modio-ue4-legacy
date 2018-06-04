#ifndef MODIO_MODIOAVATAR_H
#define MODIO_MODIOAVATAR_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitAvatar(ModioAvatar* avatar, json avatar_json);
  void modioFreeAvatar(ModioAvatar* avatar);
}

#endif
