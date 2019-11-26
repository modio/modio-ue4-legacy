#ifndef MODIO_COMMENT_H
#define MODIO_COMMENT_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioComment
#include "User.h"

namespace modio
{
class Comment
{
public:
  u32 id;
  u32 mod_id;
  u32 date_added;
  u32 reply_id;
  i32 karma;
  i32 karma_guest;
  std::string thread_position;
  std::string content;
  User user;

  void initialize(ModioComment modio_comment);
};

extern nlohmann::json toJson(Comment &comment);
} // namespace modio

#endif
