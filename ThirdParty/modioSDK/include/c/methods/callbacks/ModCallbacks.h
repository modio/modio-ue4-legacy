#ifndef MODIO_MODCALLBACKS_H
#define MODIO_MODCALLBACKS_H

#include "../../../Globals.h"
#include "../../../wrappers/MinizipWrapper.h"
#include "../../../wrappers/CurlWrapper.h"
#include "../../schemas/ModioResponse.h"
#include "../../schemas/ModioMod.h"
#include "../../../ModUtility.h"

struct GetModParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioMod mod);
};

struct GetModsParams
{
  void* object;
  std::string url;
  bool is_cache;
  void (*callback)(void* object, ModioResponse response, ModioMod mods[], u32 mods_size);
};

struct AddModParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioMod mod);
};

struct DeleteModParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

struct CallbackParamReturnsId
{
  void* object;
  u32 mod_id;
  void (*callback)(void* object, ModioResponse response, u32 mod_id);
};

extern std::map< u32,GetModParams* > get_mod_callbacks;
extern std::map< u32,AddModParams* > add_mod_callback;
extern std::map< u32,DeleteModParams* > delete_mod_callbacks;
extern std::map< u32,GetModsParams* > get_mods_callbacks;
extern std::map< u32,CallbackParamReturnsId* > return_id_callbacks;

void modioOnGetMod(u32 call_number, u32 response_code, json response_json);
void modioOnGetMods(u32 call_number, u32 response_code, json response_json);
void modioOnModAdded(u32 call_number, u32 response_code, json response_json);
void modioOnModDeleted(u32 call_number, u32 response_code, json response_json);
void modioOnReturnIdCallback(u32 call_number, u32 response_code, json response_json);

#endif
