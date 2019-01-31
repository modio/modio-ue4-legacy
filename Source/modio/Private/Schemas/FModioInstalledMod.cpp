#include "FModioInstalledMod.h"

void initializeInstalledModC(FModioInstalledMod &installed_mod, ModioInstalledMod modio_installed_mod)
{
  installed_mod.Path = UTF8_TO_TCHAR(modio_installed_mod.path);
  initializeModC(installed_mod.mod, modio_installed_mod.mod);
}