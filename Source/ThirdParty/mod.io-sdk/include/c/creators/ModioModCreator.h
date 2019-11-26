#ifndef MODIO_MODIO_MOD_CREATOR_H
#define MODIO_MODIO_MOD_CREATOR_H

#include <map>          // for map, multimap
#include <string>       // for string
#include "../ModioC.h"  // for ModioModCreator

namespace modio
{
  std::map<std::string, std::string> getModCreatorCurlFormFilesParams(ModioModCreator* mod_creator);
  std::multimap<std::string, std::string> getModCreatorCurlFormCopyContentsParams(ModioModCreator* mod_creator);
}

#endif
