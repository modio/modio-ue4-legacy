// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "FModioAvatar.h"

void InitializeAvatar(FModioAvatar &Avatar, const modio::Avatar &modio_avatar)
{
  Avatar.Filename = UTF8_TO_TCHAR(modio_avatar.filename.c_str());
  Avatar.Original = UTF8_TO_TCHAR(modio_avatar.original.c_str());
  Avatar.Thumb50x50 = UTF8_TO_TCHAR(modio_avatar.thumb_50x50.c_str());
  Avatar.Thumb100x100 = UTF8_TO_TCHAR(modio_avatar.thumb_100x100.c_str());
}

void InitializeAvatarC(FModioAvatar &Avatar, const ModioAvatar &modio_avatar)
{
  Avatar.Filename = UTF8_TO_TCHAR(modio_avatar.filename);
  Avatar.Original = UTF8_TO_TCHAR(modio_avatar.original);
  Avatar.Thumb50x50 = UTF8_TO_TCHAR(modio_avatar.thumb_50x50);
  Avatar.Thumb100x100 = UTF8_TO_TCHAR(modio_avatar.thumb_100x100);
}