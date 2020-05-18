#ifndef MODIO_MODCALLBACKS_H
#define MODIO_MODCALLBACKS_H

#include "../../../Globals.h"
#include "../../../wrappers/MinizipWrapper.h"
#include "../../../wrappers/CurlWrapper.h"
#include "../../schemas/ModioResponse.h"
#include "../../schemas/ModioMod.h"
#include "../../../ModUtility.h"
#include "../../../ModioUtility.h"

struct GetModParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioMod mod);
};

struct GetAllModsParams
{
  std::string url;
  bool is_cache;
  std::vector<void*> objects;
  std::vector<void(*)(void* object, ModioResponse response, ModioMod mods[], u32 mods_size)> callbacks;
};

struct AddModParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioMod mod);
};

struct CallbackParamReturnsId
{
  void* object;
  u32 mod_id;
  void (*callback)(void* object, ModioResponse response, u32 mod_id);
};

extern std::map< u32,GetModParams* > get_mod_callbacks;
extern std::map< u32,AddModParams* > add_mod_callbacks;
extern std::map< u32,GenericRequestParams* > delete_mod_callbacks;
extern std::map< u32,GetAllModsParams* > get_all_mods_callbacks;
extern std::map< u32,CallbackParamReturnsId* > return_id_callbacks;

void modioOnGetMod(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnGetAllMods(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnModAdded(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnModDeleted(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnReturnIdCallback(u32 call_number, u32 response_code, nlohmann::json response_json);

void clearModCallbackParams();

#endif
