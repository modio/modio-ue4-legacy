#ifndef MODIO_FILTER_H
#define MODIO_FILTER_H

#include <map>

#include "../../Globals.h"
#include "../../Utility.h"
#include "../ModioC.h"
#include "../schemas/ModioListNode.h"

namespace modio
{
  std::string getFilterString(ModioFilterCreator* filter);
}

#endif
