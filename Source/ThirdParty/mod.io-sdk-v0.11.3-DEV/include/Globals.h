#ifndef MODIO_GLOBALS_H
#define MODIO_GLOBALS_H

#include <iostream>
#include <set>

#include "Utility.h"

namespace modio
{
  extern std::string API_KEY;
  extern std::string ACCESS_TOKEN;
  extern bool IS_LOGGED_IN;
  extern u32 GAME_ID;
  extern std::string ROOT_PATH;
  extern u32 DEBUG_LEVEL;
  extern bool RETRIEVE_MODS_FROM_OTHER_GAMES;
  extern std::string MODIO_URL;
  extern std::string MODIO_VERSION_PATH;
  extern u32 MAX_CACHE_TIME;
  extern u32 LAST_MOD_EVENT_POLL_ID;
  extern u32 LAST_MOD_EVENT_POLL_TIME;
  extern u32 MOD_EVENT_POLL_INTERVAL;
  extern u32 LAST_USER_EVENT_POLL_ID;
  extern u32 LAST_USER_EVENT_POLL_TIME;
  extern u32 USER_EVENT_POLL_INTERVAL;
  extern u32 EVENT_POLL_INTERVAL;
  extern u32 AUTOMATIC_UPDATES;
  extern u32 BACKGROUND_DOWNLOADS;
  extern u32 RETRY_AFTER;
  extern ModioUser current_user;
  extern std::vector<u32> downloaded_mods;
  extern std::map<u32,u32> current_user_ratings; // maps[mod_id, rating_type]
  extern void (*event_listener_callback)(ModioResponse response, ModioModEvent* events_array, u32 events_array_size);
  extern void (*download_callback)(u32 response_code, u32 mod_id);
  extern void (*upload_callback)(u32 response_code, u32 mod_id);
  extern nlohmann::json installed_mods;
}

#endif
