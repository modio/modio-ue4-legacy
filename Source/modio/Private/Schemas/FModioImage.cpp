#include "FModioImage.h"

void initializeImage(FModioImage &Image, modio::Image modio_image)
{
  Image.Filename = UTF8_TO_TCHAR(modio_image.filename.c_str());
  Image.Original = UTF8_TO_TCHAR(modio_image.original.c_str());
  Image.Thumb320x180 = UTF8_TO_TCHAR(modio_image.thumb_320x180.c_str());
}

void initializeImageC(FModioImage &Image, ModioImage modio_image)
{
  Image.Filename = UTF8_TO_TCHAR(modio_image.filename);
  Image.Original = UTF8_TO_TCHAR(modio_image.original);
  Image.Thumb320x180 = UTF8_TO_TCHAR(modio_image.thumb_320x180);
}