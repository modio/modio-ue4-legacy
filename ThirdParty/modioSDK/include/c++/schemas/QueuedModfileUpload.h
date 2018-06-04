#ifndef MODIO_QUEUEDMODFILEUPLOAD_H
#define MODIO_QUEUEDMODFILEUPLOAD_H

#include "../../Globals.h"
#include "../../c/schemas/ModioQueuedModfileUpload.h"
#include "../creators/ModfileCreator.h"

namespace modio
{
  class QueuedModfileUpload
  {
  public:
    u32 state;
    u32 mod_id;    
    double current_progress;
    double total_size;
    std::string path;
    ModfileCreator modfile_creator;

    void initialize(ModioQueuedModfileUpload queued_modfile_upload);
    json toJson();
  };
}

#endif
