// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioInstalledMod.h"

void InitializeInstalledMod(FModioInstalledMod &installed_mod, const ModioInstalledMod &modio_installed_mod)
{
  installed_mod.Path = UTF8_TO_TCHAR(modio_installed_mod.path);
  InitializeMod(installed_mod.Mod, modio_installed_mod.mod);
}