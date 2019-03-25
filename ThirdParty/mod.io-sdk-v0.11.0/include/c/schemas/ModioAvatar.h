#ifndef MODIO_MODIOAVATAR_H
#define MODIO_MODIOAVATAR_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitAvatar(ModioAvatar* avatar, nlohmann::json avatar_json);
  void modioFreeAvatar(ModioAvatar* avatar);
}

#endif
