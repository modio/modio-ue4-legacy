#include "../../ModioUtility.h"
#include <map>
#include "../../schemas/MetadataKVP.h"

namespace modio
{
struct GetAllMetadataKVPCall
{
  const std::function<void(const modio::Response &response, std::vector<modio::MetadataKVP> metadata_kvp)> callback;
};

extern std::map<u32, GetAllMetadataKVPCall *> get_all_metadata_kvp_calls;
extern std::map<u32, GenericCall *> add_metadata_kvp_calls;
extern std::map<u32, GenericCall *> delete_metadata_kvp_calls;

void onGetAllMetadataKVP(void *object, ModioResponse modio_response, ModioMetadataKVP *metadata_kvp_array, u32 metadata_kvp_array_size);
void onAddMetadataKVP(void *object, ModioResponse modio_response);
void onDeleteMetadataKVP(void *object, ModioResponse modio_response);

void clearMetadataKVPRequestCalls();
} // namespace modio
