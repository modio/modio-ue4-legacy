#ifndef MODIO_QUEUEDMODFILEUPLOAD_H
#define MODIO_QUEUEDMODFILEUPLOAD_H

#include "../../Globals.h"
#include "../../c/schemas/ModioQueuedModfileUpload.h"
#include "../creators/ModfileCreator.h"

class ModfileCreator;

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
};

extern nlohmann::json toJson(QueuedModfileUpload &queued_modfile_upload);
} // namespace modio

#endif
