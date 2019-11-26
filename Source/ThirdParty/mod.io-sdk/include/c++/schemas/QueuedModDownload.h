#ifndef MODIO_QUEUEDMODDOWNLOAD_H
#define MODIO_QUEUEDMODDOWNLOAD_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioQueuedModDownload
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
};

extern nlohmann::json toJson(QueuedModDownload &queued_mod_download);
} // namespace modio

#endif
