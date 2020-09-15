// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioModEvent.h"

void InitializeModEvent(FModioModEvent &event, const ModioModEvent &modio_mod_event)
{
  event.Id = modio_mod_event.id;
  event.ModId = modio_mod_event.mod_id;
  event.UserId = modio_mod_event.user_id;
  event.EventType = modio_mod_event.event_type;
  event.DateAdded = modio_mod_event.date_added;
}