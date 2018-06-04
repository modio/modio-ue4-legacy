#ifndef MODIO_MODUTILITY_H
#define MODIO_MODUTILITY_H

#include "Utility.h"
#include "Globals.h"
#include "ModioUtility.h"

namespace modio
{
  void addCallToCache(std::string url, json response_json);
  std::string getCallFileFromCache(std::string url, u32 max_age_seconds);
  void addToInstalledModsJson(json mod_id, std::string path);
  bool checkIfModIsStillInstalled(std::string path, u32 mod_id);
  bool checkIfModfileIsStillInstalled(std::string path, u32 modfile_id);
  void updateInstalledModsJson();
  void checkForInstalledModsUpdates();
  std::string getInstalledModfilePath(u32 modfile_id);
  std::string getInstalledModPath(u32 mod_id);
  void updateModCache(u32 mod_id);
}

#endif
