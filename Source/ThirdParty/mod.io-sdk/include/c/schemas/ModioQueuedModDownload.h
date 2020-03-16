#ifndef MODIO_MODIOQUEUEDMODDOWNLOAD_H
#define MODIO_MODIOQUEUEDMODDOWNLOAD_H

#include "../ModioC.h"                     // for ModioQueuedModDownload
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/QueuedModDownload.h"  // for modioInitMod ...

extern "C"
{
  void modioInitQueuedModDownload(ModioQueuedModDownload* queued_mod_download, nlohmann::json queued_mod_download_json);
  void modioInitQueuedModDownloadCpp(ModioQueuedModDownload* modio_queued_mod_download, modio::QueuedModDownload* queued_mod_download);
}

#endif
