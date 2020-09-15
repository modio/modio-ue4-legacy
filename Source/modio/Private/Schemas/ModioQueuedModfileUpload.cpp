// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioQueuedModfileUpload.h"

void InitializeQueuedModfileUpload(FModioQueuedModfileUpload &queued_modfile_upload, const ModioQueuedModfileUpload &modio_queued_modfile_upload)
{
  queued_modfile_upload.State = modio_queued_modfile_upload.state;
  queued_modfile_upload.ModId = modio_queued_modfile_upload.mod_id;
  queued_modfile_upload.CurrentProgress = modio_queued_modfile_upload.current_progress;
  queued_modfile_upload.TotalSize = modio_queued_modfile_upload.total_size;
  queued_modfile_upload.Path = UTF8_TO_TCHAR(modio_queued_modfile_upload.path);
}