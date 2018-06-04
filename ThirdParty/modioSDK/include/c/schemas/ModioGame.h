#ifndef MODIO_MODIOGAME_H
#define MODIO_MODIOGAME_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioUser.h"
#include "ModioIcon.h"
#include "ModioLogo.h"
#include "ModioHeader.h"
#include "ModioGameTagOption.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitGame(ModioGame* game, json game_json);
  void modioFreeGame(ModioGame* game);
}

#endif
