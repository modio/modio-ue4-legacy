#ifndef MODIO_USER_H
#define MODIO_USER_H

#include "../../Globals.h"
#include "../../c/schemas/ModioUser.h"
#include "Avatar.h"

namespace modio
{
  class User
  {
  public:
    u32 id;
    long date_online;
    std::string username;
    std::string name_id;
    std::string timezone;
    std::string language;
    std::string profile_url;
    Avatar avatar;

    void initialize(ModioUser modio_user);
    json toJson();
  };
}

#endif
