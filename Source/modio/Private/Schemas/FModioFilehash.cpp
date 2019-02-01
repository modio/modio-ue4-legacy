// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "FModioFilehash.h"

void InitializeFilehash(FModioFilehash &Filehash, modio::Filehash modio_filehash)
{
  Filehash.Md5 = UTF8_TO_TCHAR(modio_filehash.md5.c_str());
}

void InitializeFilehashC(FModioFilehash &Filehash, ModioFilehash modio_filehash)
{
  Filehash.Md5 = UTF8_TO_TCHAR(modio_filehash.md5);
}