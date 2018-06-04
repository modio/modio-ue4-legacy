#ifndef MODIO_MEDIACALLBACKS_H
#define MODIO_MEDIACALLBACKS_H

#include "../../schemas/ModioResponse.h"
#include "../../../Globals.h"

struct AddModLogoParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

struct AddModImagesParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

struct AddModYoutubeLinksParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

struct AddModSketchfabLinksParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

struct DeleteModImagesParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

struct DeleteModYoutubeLinksParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

struct DeleteModSketchfabLinksParams
{
  void* object;
  void (*callback)(void* object, ModioResponse response);
};

extern std::map< u32, AddModLogoParams* > add_mod_logo_callbacks;
extern std::map< u32, AddModImagesParams* > add_mod_images_callbacks;
extern std::map< u32, AddModYoutubeLinksParams* > add_mod_youtube_links_callbacks;
extern std::map< u32, AddModSketchfabLinksParams* > add_mod_sketchfab_links_callbacks;
extern std::map< u32, DeleteModImagesParams* > delete_mod_images_callbacks;
extern std::map< u32, DeleteModYoutubeLinksParams* > delete_mod_youtube_links_callbacks;
extern std::map< u32, DeleteModSketchfabLinksParams* > delete_mod_sketchfab_links_callbacks;

void modioOnAddModLogo(u32 call_number, u32 response_code, json response_json);
void modioOnAddModImages(u32 call_number, u32 response_code, json response_json);
void modioOnAddModYoutubeLinks(u32 call_number, u32 response_code, json response_json);
void modioOnAddModSketchfabLinks(u32 call_number, u32 response_code, json response_json);
void modioOnDeleteModImages(u32 call_number, u32 response_code, json response_json);
void modioOnDeleteModYoutubeLinks(u32 call_number, u32 response_code, json response_json);
void modioOnDeleteModSketchfabLinks(u32 call_number, u32 response_code, json response_json);

#endif

