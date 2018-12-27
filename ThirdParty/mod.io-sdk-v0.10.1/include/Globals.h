#ifndef MODIO_GLOBALS_H
#define MODIO_GLOBALS_H

#include <iostream>
#include <set>

#include "Utility.h"

namespace modio
{
  extern std::string API_KEY;
  extern std::string ACCESS_TOKEN;
  extern u32 GAME_ID;
  extern std::string ROOT_PATH;
  extern u32 DEBUG_LEVEL;
  extern std::string MODIO_URL;
  extern std::string MODIO_VERSION_PATH;
  extern u32 MAX_CACHE_TIME;
  extern u32 LAST_MOD_EVENT_POLL;
  extern u32 LAST_USER_EVENT_POLL;
  extern u32 EVENT_POLL_INTERVAL;
  extern u32 AUTOMATIC_UPDATES;
  extern u32 BACKGROUND_DOWNLOADS;
  extern u32 RETRY_AFTER;
  extern void (*event_listener_callback)(ModioResponse response, ModioEvent* events_array, u32 events_array_size);
  extern void (*download_callback)(u32 response_code, u32 mod_id);
  extern void (*upload_callback)(u32 response_code, u32 mod_id);
  extern nlohmann::json installed_mods;
}

#endif
