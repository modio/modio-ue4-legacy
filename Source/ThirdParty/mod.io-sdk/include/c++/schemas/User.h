#ifndef MODIO_USER_H
#define MODIO_USER_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioUser
#include "Avatar.h"

namespace modio
{
class User
{
public:
  u32 id;
  u32 date_online;
  std::string username;
  std::string name_id;
  std::string timezone;
  std::string language;
  std::string profile_url;
  Avatar avatar;

  void initialize(ModioUser modio_user);
};

extern nlohmann::json toJson(User &user);
} // namespace modio

#endif
