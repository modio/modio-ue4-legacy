#ifndef MODIO_FILTER_H
#define MODIO_FILTER_H

#include <map>

#include "../../Globals.h"
#include "../../Utility.h"
#include "../ModioC.h"
#include "../schemas/ModioListNode.h"

#ifdef WINDOWS
#  ifdef BUILDING_MODIO_DLL
#    define MODIO_DLL __declspec(dllexport)
#  else
#    define MODIO_DLL __declspec(dllimport)
#  endif
#else
#  define MODIO_DLL
#endif

namespace modio
{
  std::string getFilterString(ModioFilterCreator* filter);
}

#endif
