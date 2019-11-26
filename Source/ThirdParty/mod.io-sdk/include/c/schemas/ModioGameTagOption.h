#ifndef MODIO_MODIOGAMETAGOPTION_H
#define MODIO_MODIOGAMETAGOPTION_H

#include "../ModioC.h"                     // for ModioGameTagOption
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitGameTagOption(ModioGameTagOption* game_tag_option, nlohmann::json game_tag_option_json);
  void modioFreeGameTagOption(ModioGameTagOption* game_tag_option);
}

#endif
