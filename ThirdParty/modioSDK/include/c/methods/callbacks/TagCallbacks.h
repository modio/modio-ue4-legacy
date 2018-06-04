#ifndef MODIO_TAGCALLBACKS_H
#define MODIO_TAGCALLBACKS_H

#include "../../../Globals.h"
#include "../../schemas/ModioResponse.h"
#include "../../schemas/ModioTag.h"

struct GetTagsParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioTag* tags_array, u32 tags_array_size);
};

struct EditTagsParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

struct DeleteTagsParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

extern std::map< u32, GetTagsParams* > get_tags_callbacks;
extern std::map< u32, EditTagsParams* > add_tags_callbacks;
extern std::map< u32, DeleteTagsParams* > delete_tags_callbacks;

void modioOnGetTags(u32 call_number, u32 response_code, json response_json);
void modioOnTagsAdded(u32 call_number, u32 response_code, json response_json);
void modioOnTagsDeleted(u32 call_number, u32 response_code, json response_json);

#endif
