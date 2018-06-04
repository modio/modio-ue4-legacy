#ifndef MODIO_GLOBALS_H
#define MODIO_GLOBALS_H

#include <iostream>

#include "Utility.h"

namespace modio
{
  struct CurrentDownloadInfo
  {
    std::string url;
    double download_total;
    double download_progress;
  };

  extern std::string API_KEY;
  extern std::string ACCESS_TOKEN;
  extern int GAME_ID;
  extern std::string ROOT_PATH;
  extern unsigned int DEBUG_LEVEL;
  extern std::string MODIO_URL;
  extern std::string MODIO_VERSION_PATH;
  extern u32 MAX_CALL_CACHE;
  extern u32 LAST_MOD_EVENT_POLL;
  extern u32 LAST_USER_EVENT_POLL;
  extern u32 EVENT_POLL_INTERVAL;
  extern u32 AUTOMATIC_UPDATES;
  extern u32 BACKGROUND_DOWNLOADS;
  extern void (*callback)(ModioResponse response, ModioEvent* events_array, u32 events_array_size);
  extern void (*download_callback)(u32 response_code, u32 mod_id);
  extern void (*upload_callback)(u32 response_code, u32 mod_id);
  std::vector<std::string> getHeaders();
  std::vector<std::string> getUrlEncodedHeaders();
}

#endif
