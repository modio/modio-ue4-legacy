#ifndef MODIO_AVATAR_H
#define MODIO_AVATAR_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioAvatar

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
};

extern nlohmann::json toJson(Avatar &avatar);
} // namespace modio

#endif
