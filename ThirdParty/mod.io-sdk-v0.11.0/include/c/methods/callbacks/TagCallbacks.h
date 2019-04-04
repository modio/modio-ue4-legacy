#ifndef MODIO_TAGCALLBACKS_H
#define MODIO_TAGCALLBACKS_H

#include "../../../Globals.h"
#include "../../../ModioUtility.h"
#include "../../schemas/ModioResponse.h"
#include "../../schemas/ModioTag.h"

struct GetModTagsParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioTag* tags_array, u32 tags_array_size);
};

extern std::map< u32, GetModTagsParams* > get_mod_tags_callbacks;
extern std::map< u32, GenericRequestParams* > add_mod_tags_callbacks;
extern std::map< u32, GenericRequestParams* > delete_mod_tags_callbacks;

void modioOnGetModTags(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnTagsAdded(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnTagsDeleted(u32 call_number, u32 response_code, nlohmann::json response_json);

void clearTagCallbackParams();

#endif
