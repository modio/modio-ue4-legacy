#ifndef MODIO_MODIOQUEUEDMODFILEUPLOAD_H
#define MODIO_MODIOQUEUEDMODFILEUPLOAD_H

#include "../../Utility.h"
#include "../ModioC.h"
#include "../creators/ModioModfileCreator.h"

extern "C"
{
  void modioInitQueuedModfileUpload(ModioQueuedModfileUpload* queued_modfile_upload, nlohmann::json queued_modfile_upload_json);
  void modioFreeQueuedModfileUpload(ModioQueuedModfileUpload* queued_modfile_upload);
}

#endif
