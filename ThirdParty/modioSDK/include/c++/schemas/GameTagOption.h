#ifndef MODIO_GAMETAGOPTION_H
#define MODIO_GAMETAGOPTION_H

#include "../../c/schemas/ModioGameTagOption.h"
#include "../../Globals.h"

namespace modio
{
  class GameTagOption
  {
  public:
    u32 hidden;
    std::string name;
    std::string type;
    std::vector< std::string > tags;

    void initialize(ModioGameTagOption game_tag_option);

    json toJson();
  };
}

#endif
