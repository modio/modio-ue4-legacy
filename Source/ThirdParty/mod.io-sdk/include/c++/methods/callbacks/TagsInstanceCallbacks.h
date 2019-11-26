#include "../../ModioUtility.h"
#include <map>
#include "../../schemas/Tag.h"

namespace modio
{
struct GetModTagsCall
{
  const std::function<void(const modio::Response &response, std::vector<modio::Tag> tags)> callback;
};

extern std::map<u32, GetModTagsCall *> get_mod_tags_calls;
extern std::map<u32, GenericCall *> add_mod_tags_calls;
extern std::map<u32, GenericCall *> delete_mod_tags_calls;

void onGetModTags(void *object, ModioResponse modio_response, ModioTag *tags_array, u32 tags_array_size);
void onAddModTags(void *object, ModioResponse modio_response);
void onDeleteModTags(void *object, ModioResponse modio_response);

void clearTagsRequestCalls();
} // namespace modio
