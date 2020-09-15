// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioDownload.h"

void InitializeDownload(FModioDownload &Download, const ModioDownload &modio_download)
{
  Download.DateExpires = modio_download.date_expires;
  Download.BinaryUrl = UTF8_TO_TCHAR(modio_download.binary_url);
}