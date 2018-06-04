#ifndef MODIO_IMAGECALLBACKS_H
#define MODIO_IMAGECALLBACKS_H

#include "../../schemas/ModioResponse.h"
#include "../../../Globals.h"

struct DownloadImageParams
{
  void* object;
  std::string destination_path;
  FILE* file;
  void (*callback)(void* object, ModioResponse response);
};

extern std::map< u32, DownloadImageParams* > download_image_callbacks;

void modioOnImageDownloaded(u32 call_number, u32 response_code);

#endif
