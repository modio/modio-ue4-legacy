#include "Schemas/ModioGameTagOption.h"
#include "c/schemas/ModioGameTagOption.h"

void InitializeGameTagOption(FModioGameTagOption& tag, const ModioGameTagOption& modio_game_tag_option)
{
  tag.Hidden = (bool)modio_game_tag_option.hidden;
  tag.Name = UTF8_TO_TCHAR(modio_game_tag_option.name);
  {
    tag.Tags.Reset(modio_game_tag_option.tags_array_size);
    tag.Tags.SetNum(modio_game_tag_option.tags_array_size);
    for( size_t i = 0; i < modio_game_tag_option.tags_array_size; ++i )
    {
      tag.Tags[i] = UTF8_TO_TCHAR(modio_game_tag_option.tags_array[i]);
    }
  }
  tag.Type = UTF8_TO_TCHAR(modio_game_tag_option.type);
}
