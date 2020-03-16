#ifndef MODIO_MODIOUSEREVENT_H
#define MODIO_MODIOUSEREVENT_H

#include "../ModioC.h"                     // for ModioUserEvent
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/UserEvent.h"

extern "C"
{
  void modioInitUserEvent(ModioUserEvent* event, nlohmann::json event_json);
  void modioInitUserEventCpp(ModioUserEvent* modio_user_event, modio::UserEvent* user_event);
  void modioFreeUserEvent(ModioUserEvent* event);
}

#endif
