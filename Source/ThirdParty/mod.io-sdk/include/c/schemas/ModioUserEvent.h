#ifndef MODIO_MODIOUSEREVENT_H
#define MODIO_MODIOUSEREVENT_H

#include "../ModioC.h"                     // for ModioUserEvent
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitUserEvent(ModioUserEvent* event, nlohmann::json event_json);
  void modioFreeUserEvent(ModioUserEvent* event);
}

#endif
