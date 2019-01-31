#include "FModioAvatar.h"

void initializeAvatar(FModioAvatar &Avatar, modio::Avatar modio_avatar)
{
  Avatar.Filename = UTF8_TO_TCHAR(modio_avatar.filename.c_str());
  Avatar.Original = UTF8_TO_TCHAR(modio_avatar.original.c_str());
  Avatar.Thumb50x50 = UTF8_TO_TCHAR(modio_avatar.thumb_50x50.c_str());
  Avatar.Thumb100x100 = UTF8_TO_TCHAR(modio_avatar.thumb_100x100.c_str());
}

void initializeAvatarC(FModioAvatar &Avatar, ModioAvatar modio_avatar)
{
  Avatar.Filename = UTF8_TO_TCHAR(modio_avatar.filename);
  Avatar.Original = UTF8_TO_TCHAR(modio_avatar.original);
  Avatar.Thumb50x50 = UTF8_TO_TCHAR(modio_avatar.thumb_50x50);
  Avatar.Thumb100x100 = UTF8_TO_TCHAR(modio_avatar.thumb_100x100);
}