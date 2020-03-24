#ifndef MODIO_MEDIA_H
#define MODIO_MEDIA_H

#include <string>                                 // for string
#include <list>                                   // for list
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioMedia
#include "Image.h"

namespace modio
{
class Media
{
public:
  std::vector<std::string> youtube;
  std::vector<std::string> sketchfab;
  std::list<Image> images;

  void initialize(ModioMedia media);
};

extern nlohmann::json toJson(Media &media);
} // namespace modio

#endif
