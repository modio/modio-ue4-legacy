#ifndef MODIO_MODEVENTCALLBACKS_H
#define MODIO_MODEVENTCALLBACKS_H

#include "../../../Globals.h"
#include "../../schemas/ModioResponse.h"
#include "../../schemas/ModioEvent.h"

struct GetEventsParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioEvent* events_array, u32 events_array_size);
};

struct GetAllEventsParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioEvent* events_array, u32 events_array_size);
};

extern std::map< u32, GetEventsParams* > get_events_callbacks;
extern std::map< u32, GetAllEventsParams* > get_all_events_callbacks;

void modioOnGetEvents(u32 call_number, u32 response_code, json response_json);
void modioOnGetAllEvents(u32 call_number, u32 response_code, json response_json);

#endif
