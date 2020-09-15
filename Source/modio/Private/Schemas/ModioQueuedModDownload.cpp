// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioQueuedModDownload.h"

void InitializeQueuedModDownload(FModioQueuedModDownload &queued_mod_download, const ModioQueuedModDownload &modio_queued_mod_download)
{
  queued_mod_download.Path = UTF8_TO_TCHAR(modio_queued_mod_download.path);
  queued_mod_download.CurrentProgress = modio_queued_mod_download.current_progress;
  queued_mod_download.TotalSize = modio_queued_mod_download.total_size;
  InitializeMod(queued_mod_download.mod, modio_queued_mod_download.mod);
}