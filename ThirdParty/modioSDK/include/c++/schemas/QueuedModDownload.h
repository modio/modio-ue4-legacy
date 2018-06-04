#ifndef MODIO_QUEUEDMODDOWNLOAD_H
#define MODIO_QUEUEDMODDOWNLOAD_H

#include "../../Globals.h"
#include "../../c/schemas/ModioQueuedModDownload.h"
#include "Mod.h"

namespace modio
{
  class QueuedModDownload
  {
  public:
    u32 state;
    u32 mod_id;
    double current_progress;
    double total_size;
    std::string url;
    std::string path;
    Mod mod;

    void initialize(ModioQueuedModDownload queued_mod_download);
    json toJson();
  };
}

#endif
