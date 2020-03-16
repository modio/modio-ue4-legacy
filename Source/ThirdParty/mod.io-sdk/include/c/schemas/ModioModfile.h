#ifndef MODIO_MODIOMODFILE_H
#define MODIO_MODIOMODFILE_H

#include "../ModioC.h"                     // for ModioModfile
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Modfile.h"

extern "C"
{
  void modioInitModfile(ModioModfile* modfile, nlohmann::json modfile_json);
  void modioInitModfileCpp(ModioModfile* modio_modfile, modio::Modfile* modfile);
  void modioFreeModfile(ModioModfile* modfile);
}

#endif
