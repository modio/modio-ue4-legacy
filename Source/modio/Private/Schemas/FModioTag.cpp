// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "FModioTag.h"

void InitializeTag(FModioTag &Tag, modio::Tag modio_tag)
{
  Tag.DateAdded = modio_tag.date_added;
  Tag.Name = UTF8_TO_TCHAR(modio_tag.name.c_str());
}

void InitializeTagC(FModioTag &Tag, ModioTag modio_tag)
{
  Tag.DateAdded = modio_tag.date_added;
  Tag.Name = UTF8_TO_TCHAR(modio_tag.name);
}