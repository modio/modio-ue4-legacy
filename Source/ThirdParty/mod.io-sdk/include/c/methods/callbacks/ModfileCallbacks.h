#ifndef MODIO_MODFILECALLBACKS_H
#define MODIO_MODFILECALLBACKS_H

#include "../../schemas/ModioResponse.h"
#include "../../../Globals.h"
#include "../../schemas/ModioModfile.h"
#include "../../../ModUtility.h"
#include "../../../ModioUtility.h"

struct GetModfileParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioModfile modfile);
};

struct GetAllModfilesParams
{
  void* object;
  std::string url;
  bool is_cache;
  void (*callback)(void* object, ModioResponse response, ModioModfile modfiles[], u32 modfiles_size);
};

struct AddModfileParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioModfile modfile);
};

struct EditModfileParams
{
  void* object;
  u32 modfile_id;
  void (*callback)(void* object, ModioResponse response, ModioModfile modfile);
};

extern std::map< u32, GetModfileParams* > get_modfile_callbacks;
extern std::map< u32, GetAllModfilesParams* > get_all_modfiles_callbacks;
extern std::map< u32, AddModfileParams* > add_modfile_callbacks;
extern std::map< u32, EditModfileParams* > edit_modfile_callbacks;
extern std::map< u32, GenericRequestParams* > delete_modfile_callbacks;

void modioOnGetModfile(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnGetAllModfiles(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnModfileAdded(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnModfileEdited(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnModfileDeleted(u32 call_number, u32 response_code, nlohmann::json response_json);

void clearModfileCallbackParams();

#endif
