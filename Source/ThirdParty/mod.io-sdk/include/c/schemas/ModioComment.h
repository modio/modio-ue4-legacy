#ifndef MODIO_MODIOCOMMENT_H
#define MODIO_MODIOCOMMENT_H

#include "../ModioC.h"                     // for ModioComment
#include "dependencies/nlohmann/json.hpp"  // for json

extern "C"
{
  void modioInitComment(ModioComment* comment, nlohmann::json comment_json);
  void modioFreeComment(ModioComment* comment);
}

#endif
