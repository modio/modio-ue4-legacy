#ifndef MODIO_AVATAR_H
#define MODIO_AVATAR_H

#include "../../c/schemas/ModioAvatar.h"
#include "../../Globals.h"
#include "../../Utility.h"

namespace modio
{
  class Avatar
  {
  public:
    std::string filename;
    std::string original;
    std::string thumb_50x50;
    std::string thumb_100x100;

    void initialize(ModioAvatar Avatar);
    json toJson();
  };
}

#endif
