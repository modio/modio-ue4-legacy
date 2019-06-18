#ifndef MODIO_MODIOGAME_H
#define MODIO_MODIOGAME_H

#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioUser.h"
#include "ModioIcon.h"
#include "ModioLogo.h"
#include "ModioHeader.h"
#include "ModioGameTagOption.h"

extern "C"
{
  void modioInitGame(ModioGame* game, nlohmann::json game_json);
  void modioFreeGame(ModioGame* game);
}

#endif
