#ifndef MODIO_MODIOMODEVENT_H
#define MODIO_MODIOMODEVENT_H

#include "../ModioC.h"                     // for ModioModEvent
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitModEvent(ModioModEvent* event, nlohmann::json event_json);
  void modioFreeModEvent(ModioModEvent* event);
}

#endif
