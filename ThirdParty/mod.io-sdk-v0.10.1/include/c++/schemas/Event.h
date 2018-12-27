#ifndef MODIO_MODEVENT_H
#define MODIO_MODEVENT_H

#include "../../Globals.h"
#include "../../c/schemas/ModioEvent.h"

namespace modio
{
class Event
{
public:
  u32 id;
  u32 mod_id;
  u32 user_id;
  u32 event_type;
  u32 date_added;

  void initialize(ModioEvent event);
};

extern nlohmann::json toJson(Event &event);
} // namespace modio

#endif
