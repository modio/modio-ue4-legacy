#ifndef MODIO_MODIOCOMMENT_H
#define MODIO_MODIOCOMMENT_H

#include "../../dependencies/json/json.hpp"
#include "../../Utility.h"
#include "../ModioC.h"
#include "ModioUser.h"

using json = nlohmann::json;

extern "C"
{
  void modioInitComment(ModioComment* comment, json comment_json);
  void modioFreeComment(ModioComment* comment);
}

#endif
