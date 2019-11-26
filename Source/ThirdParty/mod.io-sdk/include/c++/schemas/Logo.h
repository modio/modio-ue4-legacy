#ifndef MODIO_LOGO_H
#define MODIO_LOGO_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioLogo

namespace modio
{
class Logo
{
public:
  std::string filename;
  std::string original;
  std::string thumb_320x180;
  std::string thumb_640x360;
  std::string thumb_1280x720;

  void initialize(ModioLogo Logo);
};

extern nlohmann::json toJson(Logo &logo);
} // namespace modio

#endif
