#ifndef MODIO_MEDIACALLBACKS_H
#define MODIO_MEDIACALLBACKS_H

#include "../../schemas/ModioResponse.h"
#include "../../../Globals.h"
#include "../../../ModioUtility.h"

extern std::map< u32, GenericRequestParams* > add_mod_logo_callbacks;
extern std::map< u32, GenericRequestParams* > add_mod_images_callbacks;
extern std::map< u32, GenericRequestParams* > add_mod_youtube_links_callbacks;
extern std::map< u32, GenericRequestParams* > add_mod_sketchfab_links_callbacks;
extern std::map< u32, GenericRequestParams* > delete_mod_images_callbacks;
extern std::map< u32, GenericRequestParams* > delete_mod_youtube_links_callbacks;
extern std::map< u32, GenericRequestParams* > delete_mod_sketchfab_links_callbacks;

void modioOnAddModLogo(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnAddModImages(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnAddModYoutubeLinks(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnAddModSketchfabLinks(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnDeleteModImages(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnDeleteModYoutubeLinks(u32 call_number, u32 response_code, nlohmann::json response_json);
void modioOnDeleteModSketchfabLinks(u32 call_number, u32 response_code, nlohmann::json response_json);

void clearMediaCallbackParams();

#endif

