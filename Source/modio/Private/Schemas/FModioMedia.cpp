#include "FModioMedia.h"

void initializeMedia(FModioMedia &media, modio::Media modio_media)
{
  for (u32 i = 0; i < modio_media.youtube.size(); i++)
    media.Youtube.Add(UTF8_TO_TCHAR(modio_media.youtube[i].c_str()));
  for (u32 i = 0; i < modio_media.sketchfab.size(); i++)
    media.Sketchfab.Add(UTF8_TO_TCHAR(modio_media.sketchfab[i].c_str()));
  for (u32 i = 0; i < modio_media.images.size(); i++)
  {
    FModioImage image;
    initializeImage(image, modio_media.images[i]);
    media.Images.Add(image);
  }
}

void initializeMediaC(FModioMedia &media, ModioMedia modio_media)
{
  for (u32 i = 0; i < modio_media.youtube_size; i++)
    media.Youtube.Add(UTF8_TO_TCHAR(modio_media.youtube_array[i]));
  for (u32 i = 0; i < modio_media.sketchfab_size; i++)
    media.Sketchfab.Add(UTF8_TO_TCHAR(modio_media.sketchfab_array[i]));
  for (u32 i = 0; i < modio_media.images_size; i++)
  {
    FModioImage image;
    initializeImageC(image, modio_media.images_array[i]);
    media.Images.Add(image);
  }
}