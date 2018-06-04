#ifndef MODIO_MODIOQUEUEDMODFILEUPLOAD_H
#define MODIO_MODIOQUEUEDMODFILEUPLOAD_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"
#include "../creators/ModioModfileCreator.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitQueuedModfileUpload(ModioQueuedModfileUpload* queued_modfile_upload, json queued_modfile_upload_json);
  void modioFreeQueuedModfileUpload(ModioQueuedModfileUpload* queued_modfile_upload);
}

#endif
