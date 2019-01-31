#include "FModioFilehash.h"

void initializeFilehash(FModioFilehash &Filehash, modio::Filehash modio_filehash)
{
  Filehash.Md5 = UTF8_TO_TCHAR(modio_filehash.md5.c_str());
}

void initializeFilehashC(FModioFilehash &Filehash, ModioFilehash modio_filehash)
{
  Filehash.Md5 = UTF8_TO_TCHAR(modio_filehash.md5);
}