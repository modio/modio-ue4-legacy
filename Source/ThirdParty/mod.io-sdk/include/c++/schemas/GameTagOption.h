#ifndef MODIO_GAMETAGOPTION_H
#define MODIO_GAMETAGOPTION_H

#include <string>                                 // for string
#include <vector>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioGameTagOption

namespace modio
{
class GameTagOption
{
public:
  u32 hidden;
  std::string name;
  std::string type;
  std::vector<std::string> tags;

  void initialize(ModioGameTagOption game_tag_option);
};

extern nlohmann::json toJson(GameTagOption &game_tag_option);
} // namespace modio

#endif
