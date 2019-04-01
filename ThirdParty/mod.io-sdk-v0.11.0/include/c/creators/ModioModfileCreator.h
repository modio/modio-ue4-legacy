#ifndef MODIO_MODIO_MODFILE_CREATOR_H
#define MODIO_MODIO_MODFILE_CREATOR_H

#include "../../Globals.h"
#include "../ModioC.h"

namespace modio
{
  std::multimap<std::string, std::string> convertModfileCreatorToMultimap(ModioModfileCreator* modfile_creator);
  void modioInitModfileCreatorFromJson(ModioModfileCreator* modfile_creator, nlohmann::json modfile_creator_json);
}

#endif
