#ifndef MODIO_MODIOQUEUEDMODFILEUPLOAD_H
#define MODIO_MODIOQUEUEDMODFILEUPLOAD_H

#include "../ModioC.h"                     // for ModioQueuedModfileUpload
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/QueuedModfileUpload.h"

extern "C"
{
  void modioInitQueuedModfileUpload(ModioQueuedModfileUpload* queued_modfile_upload, nlohmann::json queued_modfile_upload_json);
  void modioFreeQueuedModfileUpload(ModioQueuedModfileUpload* queued_modfile_upload);
}

#endif
