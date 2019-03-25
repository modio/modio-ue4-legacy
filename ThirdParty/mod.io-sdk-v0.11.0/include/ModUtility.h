#ifndef MODIO_MODUTILITY_H
#define MODIO_MODUTILITY_H

#include "Utility.h"
#include "Globals.h"
#include "wrappers/MinizipWrapper.h"

namespace modio
{
  void addCallToCache(std::string url, nlohmann::json response_json);
  std::string getCallFileFromCache(std::string url, u32 max_age_seconds);
  void installDownloadedMods();
  void addToDownloadedModsJson(std::string installation_path, std::string downloaded_zip_path, nlohmann::json mod_json);
  void addToInstalledModsJson(u32 mod_id, std::string path, u32 modfile_id, u32 date_updated);
  bool checkIfModIsStillInstalled(std::string path, u32 mod_id);
  bool checkIfModfileIsStillInstalled(std::string path, u32 modfile_id);
  void updateInstalledModsJson();
  void clearOldCache();
  std::string getInstalledModPath(u32 mod_id);
  void updateModsCache(std::vector<u32> mod_ids);
}

#endif
