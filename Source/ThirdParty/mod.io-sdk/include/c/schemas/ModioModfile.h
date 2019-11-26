#ifndef MODIO_MODIOMODFILE_H
#define MODIO_MODIOMODFILE_H

#include "../ModioC.h"                     // for ModioModfile
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitModfile(ModioModfile* modfile, nlohmann::json modfile_json);
  void modioFreeModfile(ModioModfile* modfile);
}

#endif
