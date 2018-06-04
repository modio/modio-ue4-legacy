#ifndef MODIO_DOWNLOADSCALLBACKS_H
#define MODIO_DOWNLOADSCALLBACKS_H

#include "../../schemas/ModioResponse.h"
#include "../../../wrappers/MinizipWrapper.h"
#include "../../../wrappers/CurlWrapper.h"
#include "../../../Globals.h"
#include "../../../ModUtility.h"

struct GetInstallModParams
{
  u32 mod_id;
  std::string destination_path;
};

extern std::map< u32, GetInstallModParams* > get_install_mod_callbacks;

void modioOnModDownloaded(u32 call_number, u32 response_code);
void onGetInstallMod(u32 call_number, u32 response_code, json response_json);

#endif
