#ifndef MODIO_MODFILE_H
#define MODIO_MODFILE_H

#include "../../Globals.h"
#include "../../c/schemas/ModioModfile.h"
#include "Filehash.h"
#include "Download.h"

namespace modio
{
class Modfile
{
public:
  u32 id;
  u32 mod_id;
  u32 virus_status;
  u32 virus_positive;
  u32 date_added;
  u32 date_scanned;
  long filesize;
  std::string filename;
  std::string version;
  std::string virustotal_hash;
  std::string changelog;
  std::string metadata_blob;
  modio::Filehash filehash;
  modio::Download download;

  void initialize(ModioModfile modfile);
};

extern nlohmann::json toJson(Modfile &modfile);
} // namespace modio

#endif
