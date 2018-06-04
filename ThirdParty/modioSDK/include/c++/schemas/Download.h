#ifndef MODIO_DOWNLOAD_H
#define MODIO_DOWNLOAD_H

#include "../../Globals.h"
#include "../../c/schemas/ModioDownload.h"

namespace modio
{
  class Download
  {
  public:
    u32 date_expires;
    std::string binary_url;

    void initialize(ModioDownload download);
    json toJson();
  };
}

#endif
