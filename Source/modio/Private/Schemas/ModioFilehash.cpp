// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioFilehash.h"

void InitializeFilehash(FModioFilehash &Filehash, const ModioFilehash &modio_filehash)
{
  Filehash.Md5 = UTF8_TO_TCHAR(modio_filehash.md5);
}