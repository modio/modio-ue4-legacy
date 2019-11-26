#ifndef MODIO_DOWNLOAD_H
#define MODIO_DOWNLOAD_H

#include <string>                                 // for string
#include "../../dependencies/nlohmann/json.hpp"   // for json
#include "../../c/ModioC.h"                       // for ModioDownload
#include "User.h"

namespace modio
{
class Download
{
public:
  u32 date_expires;
  std::string binary_url;

  void initialize(ModioDownload download);
};

extern nlohmann::json toJson(Download &download);
} // namespace modio

#endif
