// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioImage.h"

void InitializeImage(FModioImage &Image, const ModioImage &modio_image)
{
  Image.Filename = UTF8_TO_TCHAR(modio_image.filename);
  Image.Original = UTF8_TO_TCHAR(modio_image.original);
  Image.Thumb320x180 = UTF8_TO_TCHAR(modio_image.thumb_320x180);
}