#ifndef MODIO_MODUTILITY_H
#define MODIO_MODUTILITY_H

#include <string>                          // for string
#include <vector>                          // for vector
#include "c/ModioC.h"                      // for u32
#include "dependencies/nlohmann/json.hpp"  // for json

namespace modio
{
  void addCallToCache(std::string url, nlohmann::json response_json);
  std::string getCallFileFromCache(std::string url, u32 max_age_seconds);
  void clearOldCache();
  void clearCache();
  void installDownloadedMods();
  void addToDownloadedModsJson(std::string installation_path, std::string downloaded_zip_path, nlohmann::json mod_json);
  bool checkIfModIsStillInstalled(std::string path, u32 mod_id);
  bool checkIfModfileIsStillInstalled(std::string path, u32 modfile_id);
  void updateInstalledModsJson();
  void updateDownloadedModsJson();
  std::string getInstalledModPath(u32 mod_id);
  void updateModsCache(std::vector<u32> mod_ids);
  void onCheckIfInstalledModsAreUpdated(void* object, ModioResponse response, bool mods_are_updated);
  void onInitDownloadSubscribedModfiles(void* object, ModioResponse response, bool mods_are_updated);
}

#endif
