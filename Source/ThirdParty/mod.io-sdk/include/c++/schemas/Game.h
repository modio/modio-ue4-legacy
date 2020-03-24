#ifndef MODIO_GAME_H
#define MODIO_GAME_H

#include <string>                                 // for string
#include <list>                                   // for list
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioGame
#include "User.h"
#include "Icon.h"
#include "Logo.h"
#include "Header.h"
#include "GameTagOption.h"

namespace modio
{
class Game
{
public:
  u32 id;
  u32 status;
  u32 date_added;
  u32 date_updated;
  u32 date_live;
  u32 presentation_option;
  u32 community_options;
  u32 submission_option;
  u32 curation_option;
  u32 revenue_options;
  u32 api_access_options;
  u32 maturity_options;
  std::string ugc_name;
  std::string instructions_url;
  std::string name;
  std::string name_id;
  std::string summary;
  std::string instructions;
  std::string profile_url;
  User submitted_by;
  Icon icon;
  Logo logo;
  Header header;
  std::list<GameTagOption> game_tag_options;

  void initialize(ModioGame game);
};

extern nlohmann::json toJson(Game &game);
} // namespace modio

#endif
