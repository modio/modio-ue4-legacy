#include "FModioTag.h"

void initializeTag(FModioTag &Tag, modio::Tag modio_tag)
{
  Tag.DateAdded = modio_tag.date_added;
  Tag.Name = UTF8_TO_TCHAR(modio_tag.name.c_str());
}

void initializeTagC(FModioTag &Tag, ModioTag modio_tag)
{
  Tag.DateAdded = modio_tag.date_added;
  Tag.Name = UTF8_TO_TCHAR(modio_tag.name);
}