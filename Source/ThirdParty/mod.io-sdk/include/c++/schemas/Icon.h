#ifndef MODIO_ICON_H
#define MODIO_ICON_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioIcon

namespace modio
{
class Icon
{
public:
  std::string filename;
  std::string original;
  std::string thumb_64x64;
  std::string thumb_128x128;
  std::string thumb_256x256;

  void initialize(ModioIcon Icon);
};

extern nlohmann::json toJson(Icon &icon);
} // namespace modio

#endif
