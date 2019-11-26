#ifndef MODIO_MODIODOWNLOAD_H
#define MODIO_MODIODOWNLOAD_H

#include "../ModioC.h"                     // for ModioDownload
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitDownload(ModioDownload* download, nlohmann::json download_json);
  void modioFreeDownload(ModioDownload* download);
}

#endif
