#ifndef MODIO_MOD_H
#define MODIO_MOD_H

#include <string>                                 // for string
#include <list>                                   // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioMod
#include "Logo.h"
#include "User.h"
#include "Media.h"
#include "Modfile.h"
#include "Stats.h"
#include "Tag.h"
#include "MetadataKVP.h"

namespace modio
{
class Mod
{
public:
  u32 id;
  u32 game_id;
  u32 status;
  u32 visible;
  u32 maturity_option;
  u32 date_added;
  u32 date_updated;
  u32 date_live;
  std::string homepage_url;
  std::string name;
  std::string name_id;
  std::string summary;
  std::string description;
  std::string description_plaintext;
  std::string metadata_blob;
  std::string profile_url;
  Logo logo;
  User submitted_by;
  Modfile modfile;
  Media media;
  Stats stats;
  std::list<Tag> tags;
  std::list<MetadataKVP> metadata_kvps;

  void initialize(ModioMod mod);
};

extern nlohmann::json toJson(Mod &mod);
} // namespace modio

#endif
