// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "FModioDownload.h"

void InitializeDownload(FModioDownload &Download, modio::Download modio_download)
{
  Download.DateExpires = modio_download.date_expires;
  Download.BinaryUrl = UTF8_TO_TCHAR(modio_download.binary_url.c_str());
}

void InitializeDownloadC(FModioDownload &Download, ModioDownload modio_download)
{
  Download.DateExpires = modio_download.date_expires;
  Download.BinaryUrl = UTF8_TO_TCHAR(modio_download.binary_url);
}