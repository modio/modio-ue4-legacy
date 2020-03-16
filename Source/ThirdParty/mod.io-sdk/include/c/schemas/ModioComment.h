#ifndef MODIO_MODIOCOMMENT_H
#define MODIO_MODIOCOMMENT_H

#include "../ModioC.h"                     // for ModioComment
#include "dependencies/nlohmann/json.hpp"  // for json
#include "c++/schemas/Comment.h"

extern "C"
{
  void modioInitComment(ModioComment* comment, nlohmann::json comment_json);
  void modioInitCommentCpp(ModioComment* modio_comment, modio::Comment* Comment);
  void modioFreeComment(ModioComment* comment);
}

#endif
