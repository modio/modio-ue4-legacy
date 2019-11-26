#ifndef MODIO_MODIOGAME_H
#define MODIO_MODIOGAME_H

#include "../ModioC.h"                     // for ModioGame
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitGame(ModioGame* game, nlohmann::json game_json);
  void modioFreeGame(ModioGame* game);
}

#endif
