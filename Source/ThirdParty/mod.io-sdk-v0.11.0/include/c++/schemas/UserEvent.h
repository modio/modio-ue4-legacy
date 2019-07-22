#ifndef MODIO_USEREVENT_H
#define MODIO_USEREVENT_H

#include "../../Globals.h"
#include "../../c/schemas/ModioUserEvent.h"

namespace modio
{
class UserEvent
{
public:
  u32 id;
  u32 game_id;
  u32 mod_id;
  u32 user_id;
  u32 event_type;
  u32 date_added;

  void initialize(ModioUserEvent event);
};

extern nlohmann::json toJson(UserEvent &event);
} // namespace modio

#endif
