#ifndef MODIO_MODIOMODFILE_H
#define MODIO_MODIOMODFILE_H

#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioFilehash.h"
#include "ModioDownload.h"

extern "C"
{
  void modioInitModfile(ModioModfile* modfile, nlohmann::json modfile_json);
  void modioFreeModfile(ModioModfile* modfile);
}

#endif
