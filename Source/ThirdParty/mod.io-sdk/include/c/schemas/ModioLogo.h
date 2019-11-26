#ifndef MODIO_MODIOLOGO_H
#define MODIO_MODIOLOGO_H

#include "../ModioC.h"                     // for ModioLogo
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitLogo(ModioLogo* logo, nlohmann::json logo_json);
  void modioFreeLogo(ModioLogo* logo);
}

#endif
