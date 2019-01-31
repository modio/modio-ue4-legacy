#include "FModioQueuedModDownload.h"

void initializeQueuedModDownloadC(FModioQueuedModDownload &queued_mod_download, ModioQueuedModDownload modio_queued_mod_download)
{
  queued_mod_download.Path = UTF8_TO_TCHAR(modio_queued_mod_download.path);
  queued_mod_download.CurrentProgress = modio_queued_mod_download.current_progress;
  queued_mod_download.TotalSize = modio_queued_mod_download.total_size;
  initializeModC(queued_mod_download.mod, modio_queued_mod_download.mod);
}