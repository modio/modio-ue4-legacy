#ifndef MODIO_MODFILE_CREATOR_H
#define MODIO_MODFILE_CREATOR_H

#include "../../c/creators/ModioModfileCreator.h"

namespace modio
{
class MODIO_DLL ModfileCreator
{
  ModfileCreator(const ModfileCreator&) = delete;
  ModfileCreator& operator=(const ModfileCreator&) = delete;
public:
  ModioModfileCreator modio_modfile_creator;
  ModfileCreator();
  void initializeFromModioModfileCreator(ModioModfileCreator& other_modfile_creator);
  void setPath(const std::string &path);
  void setVersion(const std::string &version);
  void setChangelog(const std::string &changelog);
  void setMetadataBlob(const std::string &metadata_blob);
  void setActive(bool active);
  void setFilehash(const std::string &filehash);
  ModioModfileCreator *getModioModfileCreator();
  ~ModfileCreator();
};

extern nlohmann::json toJson(ModfileCreator &modfile_creator);
} // namespace modio

#endif
