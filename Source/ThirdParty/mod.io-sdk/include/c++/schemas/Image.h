#ifndef MODIO_IMAGE_H
#define MODIO_IMAGE_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioImage

namespace modio
{
class Image
{
public:
  std::string filename;
  std::string original;
  std::string thumb_320x180;

  void initialize(ModioImage image);
};

extern nlohmann::json toJson(Image &image);
} // namespace modio

#endif
