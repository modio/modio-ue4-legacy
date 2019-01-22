#include "ModioSchemas.h"

void initializeMod(FModioMod &mod, modio::Mod modio_mod)
{
  mod.Id = modio_mod.id;
  mod.Name = UTF8_TO_TCHAR(modio_mod.name.c_str());
  mod.Summary = UTF8_TO_TCHAR(modio_mod.summary.c_str());
  mod.Description = UTF8_TO_TCHAR(modio_mod.description.c_str());
}

void initializeModC(FModioMod &mod, ModioMod modio_mod)
{
  mod.Id = modio_mod.id;
  mod.Name = UTF8_TO_TCHAR(modio_mod.name);
  mod.Summary = UTF8_TO_TCHAR(modio_mod.summary);
  mod.Description = UTF8_TO_TCHAR(modio_mod.description);
}

void initializeInstalledModC(FModioInstalledMod &installed_mod, ModioInstalledMod modio_installed_mod)
{
  installed_mod.Path = UTF8_TO_TCHAR(modio_installed_mod.path);
  initializeModC(installed_mod.mod, modio_installed_mod.mod);
}

void initializeQueuedModDownloadC(FModioQueuedModDownload &queued_mod_download, ModioQueuedModDownload modio_queued_mod_download)
{
  queued_mod_download.Path = UTF8_TO_TCHAR(modio_queued_mod_download.path);
  queued_mod_download.CurrentProgress = modio_queued_mod_download.current_progress;
  queued_mod_download.TotalSize = modio_queued_mod_download.total_size;
  initializeModC(queued_mod_download.mod, modio_queued_mod_download.mod);
}