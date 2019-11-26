#include "../../ModioUtility.h"
#include <map>

namespace modio
{
extern std::map<u32, GenericCall *> add_mod_logo_calls;
extern std::map<u32, GenericCall *> add_mod_images_calls;
extern std::map<u32, GenericCall *> add_mod_youtube_links_calls;
extern std::map<u32, GenericCall *> add_mod_sketchfab_links_calls;
extern std::map<u32, GenericCall *> delete_mod_images_calls;
extern std::map<u32, GenericCall *> delete_mod_sketchfab_links_calls;
extern std::map<u32, GenericCall *> delete_mod_youtube_links_calls;

void onAddModLogo(void *object, ModioResponse modio_response);
void onAddModImages(void *object, ModioResponse modio_response);
void onAddModYoutubeLinks(void *object, ModioResponse modio_response);
void onAddModSketchfabLinks(void *object, ModioResponse modio_response);
void onDeleteModImages(void *object, ModioResponse modio_response);
void onDeleteModYoutubeLinks(void *object, ModioResponse modio_response);
void onDeleteModSketchfabLinks(void *object, ModioResponse modio_response);

void clearMediaRequestCalls();
} // namespace modio
