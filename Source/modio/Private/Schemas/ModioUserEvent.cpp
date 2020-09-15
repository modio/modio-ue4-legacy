// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioUserEvent.h"

void InitializeUserEvent(FModioUserEvent &UserEvent, const ModioUserEvent &ModioUserEvent)
{
  UserEvent.Id = ModioUserEvent.id;
  UserEvent.GameId = ModioUserEvent.game_id;
  UserEvent.ModId = ModioUserEvent.mod_id;
  UserEvent.UserId = ModioUserEvent.user_id;
  UserEvent.EventType = ModioUserEvent.event_type;
  UserEvent.DateAdded = ModioUserEvent.date_added;
}