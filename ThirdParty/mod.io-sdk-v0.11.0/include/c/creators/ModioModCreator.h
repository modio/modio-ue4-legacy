#ifndef MODIO_MODIO_MOD_CREATOR_H
#define MODIO_MODIO_MOD_CREATOR_H

#include "../../Globals.h"
#include "../../Utility.h"
#include "../ModioC.h"
#include "../schemas/ModioListNode.h"

namespace modio
{
  std::map<std::string, std::string> getModCreatorCurlFormFilesParams(ModioModCreator* mod_creator);
  std::multimap<std::string, std::string> getModCreatorCurlFormCopyContentsParams(ModioModCreator* mod_creator);
}

#endif
