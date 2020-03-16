#ifndef MODIO_MODIODOWNLOAD_H
#define MODIO_MODIODOWNLOAD_H

#include "../ModioC.h"                     // for ModioDownload
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Download.h"

extern "C"
{
  void modioInitDownload(ModioDownload* download, nlohmann::json download_json);
  void modioInitDownloadCpp(ModioDownload* modio_download, modio::Download* download);
  void modioFreeDownload(ModioDownload* download);
}

#endif
