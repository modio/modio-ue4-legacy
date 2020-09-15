// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioLogo.h"

void InitializeLogo(FModioLogo &Logo, const ModioLogo &modio_logo)
{
  Logo.Filename = UTF8_TO_TCHAR(modio_logo.filename);
  Logo.Original = UTF8_TO_TCHAR(modio_logo.original);
  Logo.Thumb320x180 = UTF8_TO_TCHAR(modio_logo.thumb_320x180);
  Logo.Thumb640x360 = UTF8_TO_TCHAR(modio_logo.thumb_640x360);
  Logo.Thumb1280x720 = UTF8_TO_TCHAR(modio_logo.thumb_1280x720);
}