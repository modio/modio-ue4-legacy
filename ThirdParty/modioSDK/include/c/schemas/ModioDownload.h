#ifndef MODIO_MODIODOWNLOAD_H
#define MODIO_MODIODOWNLOAD_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitDownload(ModioDownload* download, json download_json);
  void modioFreeDownload(ModioDownload* download);
}

#endif
