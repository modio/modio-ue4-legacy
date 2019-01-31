#include "FModioDownload.h"

void initializeDownload(FModioDownload &Download, modio::Download modio_download)
{
  Download.DateExpires = modio_download.date_expires;
  Download.BinaryUrl = UTF8_TO_TCHAR(modio_download.binary_url.c_str());
}

void initializeDownloadC(FModioDownload &Download, ModioDownload modio_download)
{
  Download.DateExpires = modio_download.date_expires;
  Download.BinaryUrl = UTF8_TO_TCHAR(modio_download.binary_url);
}