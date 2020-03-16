#ifndef MODIO_MODIOGAME_H
#define MODIO_MODIOGAME_H

#include "../ModioC.h"                     // for ModioGame
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Game.h"

extern "C"
{
  void modioInitGame(ModioGame* game, nlohmann::json game_json);
  void modioInitGameCpp(ModioGame* modio_game, modio::Game* Game);
  void modioFreeGame(ModioGame* game);
}

#endif
