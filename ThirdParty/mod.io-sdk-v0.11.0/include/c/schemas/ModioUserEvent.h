#ifndef MODIO_MODIOUSEREVENT_H
#define MODIO_MODIOUSEREVENT_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitUserEvent(ModioUserEvent* event, nlohmann::json event_json);
  void modioFreeUserEvent(ModioUserEvent* event);
}

#endif
