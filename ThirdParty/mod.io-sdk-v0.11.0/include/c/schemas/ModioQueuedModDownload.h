#ifndef MODIO_MODIOQUEUEDMODDOWNLOAD_H
#define MODIO_MODIOQUEUEDMODDOWNLOAD_H

#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioMod.h"

extern "C"
{
  void modioInitQueuedModDownload(ModioQueuedModDownload* queued_mod_download, nlohmann::json queued_mod_download_json);
  void modioFreeQueuedModDownload(ModioQueuedModDownload* queued_mod_download);
}

#endif
