#ifndef MODIO_MODIOMODEVENT_H
#define MODIO_MODIOMODEVENT_H

#include "../ModioC.h"                     // for ModioModEvent
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/ModEvent.h"

extern "C"
{
  void modioInitModEvent(ModioModEvent* event, nlohmann::json event_json);
  void modioInitModEventCpp(ModioModEvent* modio_mod_event, modio::ModEvent* mod_event);
  void modioFreeModEvent(ModioModEvent* event);
}

#endif
