#ifndef MODIO_GLOBALS_H
#define MODIO_GLOBALS_H

#include <map>                             // for map
#include <set>                             // for set
#include <string>                          // for string
#include <vector>                          // for vector
#include "c/ModioC.h"                      // for u32, ModioModEvent, ModioR...
#include "dependencies/nlohmann/json.hpp"  // for json

namespace modio
{
  extern std::string VERSION;
  extern std::string API_KEY;
  extern std::string ACCESS_TOKEN;
  extern bool IS_LOGGED_IN;
  extern u32 GAME_ID;
  extern std::string ROOT_PATH;
  extern std::string ADDITIONAL_GAMEDIR_PATH;
  extern u32 DEBUG_LEVEL;
  extern bool RETRIEVE_MODS_FROM_OTHER_GAMES;
  extern bool POLLING_ENABLED;
  extern std::string MODIO_URL;
  extern std::string MODIO_VERSION_PATH;
  extern u32 MAX_CACHE_TIME_SECONDS;
  extern u32 LAST_MOD_EVENT_POLL_ID;
  extern u32 LAST_MOD_EVENT_POLL_TIME;
  extern u32 MOD_EVENT_POLL_INTERVAL;
  extern u32 MOD_EVENT_MINIMUM_POLL_INTERVAL;
  extern u32 LAST_USER_EVENT_POLL_ID;
  extern u32 LAST_USER_EVENT_POLL_TIME;
  extern u32 USER_EVENT_POLL_INTERVAL;
  extern u32 USER_EVENT_MINIMUM_POLL_INTERVAL;
  extern u32 EVENT_POLL_INTERVAL;
  extern u32 AUTOMATIC_UPDATES;
  extern u32 BACKGROUND_DOWNLOADS;
  extern u32 RETRY_AFTER;
  extern ModioUser current_user;
  extern std::map<u32,u32> current_user_ratings; // maps[mod_id, rating_type]
  extern std::set<u32> current_user_subscriptions; // set[mod_id]
  extern void (*event_listener_callback)(ModioResponse response, ModioModEvent* events_array, u32 events_array_size);
  extern void (*download_callback)(u32 response_code, u32 mod_id);
  extern void (*upload_callback)(u32 response_code, u32 mod_id);
  extern nlohmann::json installed_mods;
  extern nlohmann::json g_downloaded_mods;
}

#endif
