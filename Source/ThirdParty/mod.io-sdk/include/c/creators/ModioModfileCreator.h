#ifndef MODIO_MODIO_MODFILE_CREATOR_H
#define MODIO_MODIO_MODFILE_CREATOR_H

#include <map>                             // for multimap
#include <string>                          // for string
#include "../ModioC.h"                     // for ModioModfileCreator
#include "dependencies/nlohmann/json.hpp"  // for json

namespace modio
{
  std::multimap<std::string, std::string> convertModfileCreatorToMultimap(ModioModfileCreator* modfile_creator);
  void modioInitModfileCreatorFromJson(ModioModfileCreator* modfile_creator, nlohmann::json modfile_creator_json);
}

#endif
