#ifndef MODIO_MODIODOWNLOAD_H
#define MODIO_MODIODOWNLOAD_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitDownload(ModioDownload* download, nlohmann::json download_json);
  void modioFreeDownload(ModioDownload* download);
}

#endif
