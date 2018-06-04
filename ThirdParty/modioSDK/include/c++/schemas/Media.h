#ifndef MODIO_MEDIA_H
#define MODIO_MEDIA_H

#include "../../c/schemas/ModioMedia.h"
#include "Image.h"
#include "../../Globals.h"

namespace modio
{
  class Media
  {
  public:
    std::vector<std::string> youtube;
    std::vector<std::string> sketchfab;
    std::vector<Image> images;

    void initialize(ModioMedia media);
    json toJson();
  };
}

#endif
