// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioUE4Utility.h"

FString current_user_username;

TArray<FModioMod> toTArrayMods(ModioMod* modio_mods, u32 mods_size)
{
  TArray<FModioMod> mods;
  for (u32 i = 0; i < mods_size; i++)
  {
    FModioMod mod;
    InitializeMod(mod, modio_mods[i]);
    mods.Add(mod);
  }
  return mods;
}