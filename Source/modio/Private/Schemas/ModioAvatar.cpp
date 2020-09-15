// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioAvatar.h"

void InitializeAvatar(FModioAvatar &Avatar, const ModioAvatar &modio_avatar)
{
  Avatar.Filename = UTF8_TO_TCHAR(modio_avatar.filename);
  Avatar.Original = UTF8_TO_TCHAR(modio_avatar.original);
  Avatar.Thumb50x50 = UTF8_TO_TCHAR(modio_avatar.thumb_50x50);
  Avatar.Thumb100x100 = UTF8_TO_TCHAR(modio_avatar.thumb_100x100);
}