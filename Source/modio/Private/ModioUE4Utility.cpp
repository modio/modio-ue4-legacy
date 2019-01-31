#include "ModioUE4Utility.h"

TArray<FModioMod> toTArrayMods(const std::vector<modio::Mod> &modio_mods)
{
  TArray<FModioMod> mods;
  for (u32 i = 0; i < modio_mods.size(); i++)
  {
    FModioMod mod;
    initializeMod(mod, modio_mods[i]);
    mods.Add(mod);
  }
  return mods;
}