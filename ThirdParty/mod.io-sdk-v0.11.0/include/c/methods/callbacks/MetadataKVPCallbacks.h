#ifndef MODIO_METADATAKVPCALLBACKS_H
#define MODIO_METADATAKVPCALLBACKS_H

#include "../../../Globals.h"
#include "../../../ModioUtility.h"
#include "../../schemas/ModioResponse.h"
#include "../../schemas/ModioMetadataKVP.h"

struct GetAllMetadataKVPParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response, ModioMetadataKVP* metadata_kvp_array, u32 metadata_kvp_array_size);
};

extern std::map< u32, GetAllMetadataKVPParams* > get_all_metadata_kvp_callbacks;
extern std::map< u32, GenericRequestParams* > add_metadata_kvp_callbacks;
extern std::map< u32, GenericRequestParams* > delete_metadata_kvp_callbacks;

void modioOnGetAllMetadataKVP(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnAddMetadataKVP(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnDeleteMetadataKVP(u32 call_number, u32 response_code, nlohmann::json response_json);

void clearMetadataKVPCallbackParams();

#endif
