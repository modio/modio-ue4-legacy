#ifndef MODIO_MODIOMODEVENT_H
#define MODIO_MODIOMODEVENT_H

#include "../../Utility.h"
#include "../ModioC.h"

extern "C"
{
  void modioInitModEvent(ModioModEvent* event, nlohmann::json event_json);
  void modioFreeModEvent(ModioModEvent* event);
}

#endif
