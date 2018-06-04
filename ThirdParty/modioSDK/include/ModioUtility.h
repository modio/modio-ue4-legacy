#include "Utility.h"
#include "Globals.h"
#include "c/ModioC.h"
#include "c++/schemas/Mod.h"

namespace modio
{
  void onGetInstalledMods(void* object, ModioResponse response, ModioMod* mods, u32 mods_size);
  void onModUpdateEvent(void* object, ModioResponse response, ModioMod modio_mod);
  void onGetAllEventsPoll(void* object, ModioResponse response, ModioEvent* events_array, u32 events_array_size);
  void pollEvents();
}
