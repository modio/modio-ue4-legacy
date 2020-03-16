#ifndef MODIO_MODIOLOGO_H
#define MODIO_MODIOLOGO_H

#include "../ModioC.h"                     // for ModioLogo
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Logo.h"

extern "C"
{
  void modioInitLogo(ModioLogo* logo, nlohmann::json logo_json);
  void modioInitLogoCpp(ModioLogo* modio_logo, modio::Logo* logo);
  void modioFreeLogo(ModioLogo* logo);
}

#endif
