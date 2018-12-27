#ifndef MODIO_MODSTATSCALLBACKS_H
#define MODIO_MODSTATSCALLBACKS_H

#include "../../../Globals.h"
#include "../../../wrappers/MinizipWrapper.h"
#include "../../../wrappers/CurlWrapper.h"
#include "../../schemas/ModioResponse.h"
#include "../../schemas/ModioStats.h"
#include "../../../ModUtility.h"

struct GetModStatsParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioStats stats);
};

struct GetAllModStatsParams
{
  void* object;
  std::string url;
  bool is_cache;
  void (*callback)(void* object, ModioResponse response, ModioStats mods_stats[], u32 mods_stats_size);
};

extern std::map< u32,GetModStatsParams* > get_mod_stats_callbacks;
extern std::map< u32,GetAllModStatsParams* > get_all_mod_stats_callbacks;

void modioOnGetModStats(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnGetAllModStats(u32 call_number, u32 response_code, nlohmann::json response_json);

void clearModStatsCallbackParams();

#endif
