// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "FModioUser.h"

void InitializeUser(FModioUser &User, modio::User modio_user)
{
  User.Id = modio_user.id;
  User.DateOnline = modio_user.date_online;
  User.Username = UTF8_TO_TCHAR(modio_user.username.c_str());
  User.NameId = UTF8_TO_TCHAR(modio_user.name_id.c_str());
  User.Timezone = UTF8_TO_TCHAR(modio_user.timezone.c_str());
  User.Language = UTF8_TO_TCHAR(modio_user.language.c_str());
  User.ProfileUrl = UTF8_TO_TCHAR(modio_user.profile_url.c_str());
  InitializeAvatar(User.Avatar, modio_user.avatar);
}

void InitializeUserC(FModioUser &User, ModioUser modio_user)
{
  User.Id = modio_user.id;
  User.DateOnline = modio_user.date_online;
  User.Username = UTF8_TO_TCHAR(modio_user.username);
  User.NameId = UTF8_TO_TCHAR(modio_user.name_id);
  User.Timezone = UTF8_TO_TCHAR(modio_user.timezone);
  User.Language = UTF8_TO_TCHAR(modio_user.language);
  User.ProfileUrl = UTF8_TO_TCHAR(modio_user.profile_url);
  InitializeAvatarC(User.Avatar, modio_user.avatar);
}