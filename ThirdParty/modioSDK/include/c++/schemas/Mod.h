#ifndef MODIO_MOD_H
#define MODIO_MOD_H

#include "../../Utility.h"
#include "../../Globals.h"
#include "../../ModUtility.h"
#include "Logo.h"
#include "User.h"
#include "Media.h"
#include "Modfile.h"
#include "RatingSummary.h"
#include "Tag.h"
#include "MetadataKVP.h"
#include "../../c/schemas/ModioMod.h"

namespace modio
{
  class Mod
  {
  public:
    u32 id;
    u32 game_id;
    u32 status;
    u32 visible;
    long date_added;
    long date_updated;
    long date_live;
    std::string homepage_url;
    std::string name;
    std::string name_id;
    std::string summary;
    std::string description;
    std::string metadata_blob;
    std::string profile_url;
    Logo logo;
    User submitted_by;
    Modfile modfile;
    Media media;
    RatingSummary rating_summary;
    std::vector<Tag> tags;
    std::vector<MetadataKVP> metadata_kvps;

    void initialize(ModioMod mod);
    json toJson();
  };
}

#endif
