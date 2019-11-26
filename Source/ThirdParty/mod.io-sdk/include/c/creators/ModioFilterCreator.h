#ifndef MODIO_FILTER_H
#define MODIO_FILTER_H

#include <map>

#include <string>                             // for string
#include "../ModioC.h"  // for ModioFilterCreator

namespace modio
{
  std::string getFilterString(ModioFilterCreator* filter);
}

#endif
