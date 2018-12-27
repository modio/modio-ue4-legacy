#ifndef MODIO_MODIOMODEVENT_H
#define MODIO_MODIOMODEVENT_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitEvent(ModioEvent* event, nlohmann::json event_json);
  void modioFreeEvent(ModioEvent* event);
}

#endif
