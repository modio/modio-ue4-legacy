#include "../../ModioUtility.h"
#include <map>

namespace modio
{
extern std::map<u32, GenericCall *> download_image_calls;

void onDownloadImage(void *object, ModioResponse modio_response);

void clearImageRequestCalls();
} // namespace modio
