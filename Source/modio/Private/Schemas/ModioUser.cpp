// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioUser.h"

void InitializeUser(FModioUser &User, const ModioUser &modio_user)
{
  User.Id = modio_user.id;
  User.DateOnline = modio_user.date_online;
  User.Username = UTF8_TO_TCHAR(modio_user.username);
  User.NameId = UTF8_TO_TCHAR(modio_user.name_id);
  User.Timezone = UTF8_TO_TCHAR(modio_user.timezone);
  User.Language = UTF8_TO_TCHAR(modio_user.language);
  User.ProfileUrl = UTF8_TO_TCHAR(modio_user.profile_url);
  InitializeAvatar(User.Avatar, modio_user.avatar);
}