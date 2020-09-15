// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioModTag.h"

void InitializeModTag(FModioModTag &Tag, const ModioTag &modio_tag)
{
  Tag.DateAdded = modio_tag.date_added;
  Tag.Name = UTF8_TO_TCHAR(modio_tag.name);
}