#ifndef MODIO_MODIOGAMETAGOPTION_H
#define MODIO_MODIOGAMETAGOPTION_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitGameTagOption(ModioGameTagOption* game_tag_option, json game_tag_option_json);
  void modioFreeGameTagOption(ModioGameTagOption* game_tag_option);
}

#endif
